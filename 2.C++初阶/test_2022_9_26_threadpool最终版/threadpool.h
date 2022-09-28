#pragma once
#pragma once
#include<iostream>
#include<unordered_map>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<functional>
#include<memory>
#include<queue>
#include<sstream>
#include<atomic>
#include<future>
using std::cout;
using std::endl;

//��־��ӡ
#define INFO 1
#define WARNING 2
#define ERROR_ 3
#define FALTA 4

#define LOG(level,message)  log(#level,message,__FILE__,__LINE__)
static void log(std::string level, std::string message, std::string file_name, int line) {
	//��ʾ��ǰ�¼�
	char now[1024] = { 0 };
	time_t tt = time(nullptr);
	struct tm* ttime;
	ttime = localtime(&tt);
	strftime(now, 1024, "%Y-%m-%d %H:%M:%S", ttime);
	// cout << "[" << now << "" << "][" << level << "]" << "[" << message << "]" << "[" << file_name << "]" << "[" << line << "]" << endl;

	printf("[%s][%s][%s][%s][%d]\n", now, level.c_str(), message.c_str(), file_name.c_str(), line);

}

const int TASKQUE_MAX_SIZE_DEFAULT = 2;
const int THREAD_INIT_SIZE_DEFAULT = 5;
const int THREAD_MAX_SIZE_DEFAULT = 20;

enum class PoolMode {
	FIXED_MODE,
	CACHED_MODE
};

class Thread {
public:
	using Func = std::function<void(int)>;
	Thread(Func _func) :id_(ID++), func_(_func) {

	}


	void start()
	{
		std::thread t(func_, id_);
		t.detach();
	}
	int get_id()
	{
		return id_;
	}
private:
	int id_;
	static std::atomic_int ID;
	Func func_;
};
std::atomic_int Thread::ID = 0;

class ThreadPool {
public:
	//���캯����ʼ��
	ThreadPool() :threadInitSize_(THREAD_INIT_SIZE_DEFAULT),
		taskQueMaxSize_(TASKQUE_MAX_SIZE_DEFAULT),
		threadMaxSize_(THREAD_MAX_SIZE_DEFAULT),
		taskQueSize_(0),
		curThreadSize_(0),
		freeThreadSize_(0),
		mode_(PoolMode::FIXED_MODE),
		IsRunning_(false) {

	}

	~ThreadPool() {
		IsRunning_ = false;
		std::unique_lock<std::mutex>lock(taskMtx_);
		Not_Empty.notify_all();
		cond_exit.wait(lock, [&]()->bool {
			return threads_.size() == 0;
			});
	}

	//��������������ֵ
	void SetTaskQueMaxSize(int size = TASKQUE_MAX_SIZE_DEFAULT)
	{
		if (IsPoolRunning())
		{
			LOG(WARNING, "ThreadPool is already Runing,can not set taskQue max size!");
			return;
		}
		this->taskQueMaxSize_ = size;
	}

	//�����̳߳�ģʽ
	void SetThreadPoolMode(PoolMode mode = PoolMode::FIXED_MODE) {
		if (IsPoolRunning())
		{
			LOG(WARNING, "ThreadPool is already Runing,can not set ThreadPool Mode!");
		}
		this->mode_ = mode;
	}

	//����cachedģʽ���̵߳����ֵ
	void SetThreasMaxSize(int size = THREAD_MAX_SIZE_DEFAULT) {
		if (mode_ == PoolMode::FIXED_MODE)
		{
			LOG(WARNING, "ThreadPool is FIXED_MODE,can not set threads max size!");
			return;
		}
		if (IsPoolRunning())
		{
			LOG(WARNING, "ThreadPool is already Runing,can not threads mas size!");
			return;
		}
		this->threadMaxSize_ = size;
	}

	//start�����̳߳�
	void start(int size = std::thread::hardware_concurrency()) {
		IsRunning_ = true;
		this->threadInitSize_ = size;
		this->curThreadSize_ = size;
		this->freeThreadSize_ = size;
		for (int i = 0; i < threadInitSize_; i++)
		{
			auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::func, this, std::placeholders::_1));
			int id = ptr->get_id();
			//std::cout << id << std::endl;
			threads_.emplace(id, std::move(ptr));
		}

		for (int i = 0; i < threadInitSize_; i++)
		{
			//cout << i << endl;
			threads_[i]->start();
		}
	}

	//���̳߳��ύ����
	template<typename Func,typename...Args>
	auto submitTask(Func&& func,Args&&... args) -> std::future<decltype(func(args...))>
	{
		//�ȴ��������Ȼ���ȡ��
		using RTtype = decltype(func(args...));
		auto ptr = std::make_shared<std::packaged_task<RTtype()>>(
			std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
		std::future<RTtype>ret = ptr->get_future();

		std::unique_lock<std::mutex>lock(this->taskMtx_);
		if (Not_Full.wait_for(lock, std::chrono::seconds(3), [&]()->bool {
			return taskQue_.size() < taskQueMaxSize_;
			}) == false)
		{
			LOG(WARNING, "taskQue is full");
			auto task = std::make_shared<std::packaged_task<RTtype()>>(
				[]()->RTtype {
					return RTtype();
				}
			);
			(* task)();
			return  task->get_future();
		}
			//std::cout << "�������ɹ�" << endl;
			//���ڻ�ȡ��֮������������������ͬʱ�ж��Ƿ�Ϊcachedģʽ�������cachedģʽ����ô����Ҫ����
			//�жϵ�ǰ�����߳������ǲ���С�����������ͬʱ�߳�����С��cachedģʽ����߳�����

			//������������Ԫ��
			taskQue_.emplace([ptr]()->void {
				(*ptr)();
				});
		//	cout << "�������ɹ�" << endl;
			taskQueSize_++;
			//֪ͨ�����߳̽�������
			Not_Empty.notify_all();


			//�ж��ǲ�����Ҫ����߳�
			if (mode_ == PoolMode::CACHED_MODE
				&& freeThreadSize_ < taskQueSize_
				&& curThreadSize_ < threadMaxSize_)
			{
				//�������̣߳����뵽unordered_map�У������������߳�
				auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::func, this, std::placeholders::_1));
				int id = ptr->get_id();
				threads_.emplace(id, std::move(ptr));
				threads_[id]->start();
				this->curThreadSize_++;
				this->freeThreadSize_++;
				LOG(INFO, "Add a new thread:" + std::to_string(id));
			}
			return ret;
	}

private:
	using Task = std::function<void()>;
	std::unordered_map<int, std::unique_ptr<Thread>>threads_;       //����̵߳�����
	std::queue <Task>taskQue_;                    //�������Ķ���

	int threadInitSize_;              //�̳߳س�ʼ���̸߳���
	int taskQueMaxSize_;              //����������������������һ��ΪINT_MAX
	int threadMaxSize_;               //cachedģʽ������̸߳�������ֹ��Ϊ�߳�һֱ��������ϵͳ��Դռ�ù���
	std::atomic_int taskQueSize_ = 0; //���taskQue_��size

	std::atomic_int curThreadSize_;               //��ǰ�̸߳������������߳�+˯���߳�
	std::atomic_int freeThreadSize_;              //��¼��ǰ���е�˯���߳�

	std::mutex taskMtx_;                  //��������ʹ�ö�taskQue_���в�����ԭ�ӵ�
	std::condition_variable Not_Empty;    //��������������ǰ������в�Ϊ�գ��������߳̽���������
	std::condition_variable Not_Full;     //��������������ǰtaskQue_���������ǿ�����������������������
	std::condition_variable cond_exit;    //�����������˳�ʱ�ж���������Ƿ�Ϊ�գ���ʱ�����������ִ�У���ô��ִ���굱ǰ��������˳�

	PoolMode mode_;                  //��¼�̳߳ص�ǰ����״̬
	bool IsRunning_;                 //�ж��̳߳��Ƿ�������

	bool IsPoolRunning()    //�ж��̳߳��Ƿ�������
	{
		return IsRunning_;
	}
	//ִ���߳�����
	void func(int id)
	{
		//cout << std::this_thread::get_id() << "ִ���߳�" << endl;
		//���ÿ���߳����һ�η���ʱ��
		auto LastTime = std::chrono::high_resolution_clock::now();
		Task task;
		for (;;)
		{

			//cout << std::this_thread::get_id() << ":taskQueSIze:" << taskQue_.size() << endl;

			{
				//��ȡ��
				std::unique_lock<std::mutex>lock(taskMtx_);
				cout << std::this_thread::get_id() << " ��ȡ��" << endl;
				//�����ȴ���ֱ��taskQue������Ԫ�����ٽ�������
				while (IsPoolRunning() && taskQue_.size() == 0)
				{
					//�����cachedģʽ���������ȴ�һ��ʱ�䣬�ж��Ƿ�ʱ�������ʱ����ô���ǾͿ�����̵߳Ĵ���ʱ���Ƿ�
					//����ָ��ʱ�䣬���Ǿ�ɱ����ǰ����
					if (mode_ == PoolMode::CACHED_MODE)
					{
						//�����ȴ����жϵȴ�ʱ���Ƿ�ʱ�ˣ������ʱ����ɱ����ǰ����
						if (std::cv_status::timeout == Not_Empty.wait_for(lock, std::chrono::seconds(3)))
						{
							//cout << "jejej" << endl;
							auto now = std::chrono::high_resolution_clock::now();
							//��������涨ʱ���ɱ���߳�
							auto mul = std::chrono::duration_cast<std::chrono::seconds>(now - LastTime);
							//cout << std::this_thread::get_id() << " " << curThreadSize_ << " " << threadInitSize_ << endl;
							if (mul.count() >= 3 && curThreadSize_ > threadInitSize_)
							{
								//cout << "ɱ���߳�" << std::this_thread::get_id() << " " << curThreadSize_ << " " << threadInitSize_ << endl;
								auto it = threads_.find(id);
								if (it != threads_.end())
								{
									threads_.erase(it);
									curThreadSize_--;
									freeThreadSize_--;
									//ɾ��֮��֪ͨ���߳̿��Ƿ��˳�
									std::stringstream ss;
									ss << "id:";
									ss << std::this_thread::get_id();
									ss << " deleted";
									LOG(INFO, ss.str());
								}
								cond_exit.notify_all();
								return;
							}
						}
					}
					else
					{
						//cout << "heeeeheh" << endl;
						//FIXEDģʽ�¾�һֱ�ȴ��Ƿ���������
						Not_Empty.wait(lock);
					}
				}
				if (IsPoolRunning() == false && taskQue_.size() == 0)
				{
					auto it = threads_.find(id);
					if (it != threads_.end())
					{
						threads_.erase(it);
						curThreadSize_--;
						freeThreadSize_--;
						//ɾ��֮��֪ͨ���߳̿��Ƿ��˳�
						std::stringstream ss;
						ss << "id:";
						ss << std::this_thread::get_id();
						ss << " deleted";
						LOG(INFO, ss.str());
					}
					cond_exit.notify_all();
					return;
				}
				//��ʱ������������������ˣ������������
				task = taskQue_.front();
				taskQue_.pop();
				taskQueSize_--;
				freeThreadSize_--;


				std::cout << std::this_thread::get_id() << "��ȡ����ɹ�" << std::endl;
				//�����ʱ�������񣬾�֪ͨ�����������߳̽�������
				if (taskQue_.size() > 0)
					Not_Empty.notify_all();
				//��ʱȡ������֮�����������в����ˣ����ǾͿ���֪ͨ�������߳�(submitTask)��������
				Not_Full.notify_all();
			}

			//cout << "ִ������" << endl;
			if(task!=nullptr)
			task();

			freeThreadSize_++;
			LastTime = std::chrono::high_resolution_clock::now(); //�����߳����һ�η���ʱ��
		}
	}
};