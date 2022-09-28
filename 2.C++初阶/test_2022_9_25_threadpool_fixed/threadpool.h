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

const int TASKQUE_MAX_SIZE_DEFAULT = 10;
const int THREAD_INIT_SIZE_DEFAULT = 5;
const int THREAD_MAX_SIZE_DEFAULT = 20;

enum class PoolMode {
	FIXED_MODE,
	CACHED_MODE
};


//���������������ⷵ��ֵ���͵�Any����
class Any {
public:
	Any() {

	}
	//ɾ����������͸������������
	Any(const Any&) = delete;
	Any& operator=(const Any&) = delete;

	//��ֵ���õĿ�������͸�ֵ�������������Ĭ�����ɵľͿ�����
	Any(Any&&) = default;
	Any& operator= (Any&&) = default;
	template<class T>
	Any(T data) :ptr_(std::make_unique<Derive<T>>(data)) {

	}
	template<class T>
	T get_cast()
	{
		auto*p = dynamic_cast<Derive<T>*>(ptr_.get());
		if (p == nullptr)
		{
			//std::throw "type is error";
		}
		return p->get();
	}

	
private:
	class Base {
	public:
		virtual ~Base() {

		}
	};

	template<class T>
	class Derive :public Base {
	public:
		Derive(T data_) :data(data_) {

		}
		T get() {
			return data;
		}
	private:
		T data;
	};

	std::unique_ptr<Base>ptr_;
};

//�������̺߳����߳�֮�����ͨ�ŵ�Semaphore�ź���
class Semaphore {
public:
	//�ȴ���Դ
	void wait() {
		std::unique_lock<std::mutex>lock(mtx_);
		cond_.wait(lock, [&]()->bool {
			return limited_ > 0;
			});
		limited_--;
		//cout <<std::this_thread::get_id() <<"Wait:" << limited_ << "-------------------" << endl;
	
	}
	//�õ���Դ
	void post() {
		std::unique_lock<std::mutex>lock(mtx_);
		limited_++;
		//cout <<std::this_thread::get_id() << " Post:" << limited_ << "+++++++++++++++++++" << endl;
		cond_.notify_all();
	}

private:
	int limited_=0;    
	std::condition_variable cond_;
	std::mutex mtx_;
};


class Task;  //ǰ������Task;
class Result {
public:

	//���뵱ǰִ�е�task����ָ��
	Result(std::shared_ptr<Task> s, bool isSet = true);

	void SetVal(Any val);  //��task_�����ûص�

	Any get();               //�õ��߳�ִ�еķ���ֵany
private:
	Any any_;  //�洢�߳�ִ��������ķ���ֵany
	Semaphore sem_;//�洢
	std::shared_ptr<Task>task_;
	bool isSet_;
};



class Task {
public:

	virtual Any Run() = 0;      //�ṩ�����������д�Ľӿ�
	void exec();                //ר������ִ��Run�����ҽ�����ֵд��res.setVal��

	void setRes(Result* res);   //����res
private:

	Result* res_=nullptr;
};




class Thread {
public:
	using Func = std::function<void(int)>;
	Thread(Func _func) :id_(ID++),func_(_func) {

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


class ThreadPool{
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
			auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::func,this,std::placeholders::_1));
			int id = ptr->get_id();
			//std::cout << id << std::endl;
			threads_.emplace(id, std::move(ptr));
		}

		for (int i = 0; i < threadInitSize_; i++)
		{
			threads_[i]->start();
		}
	}

	//���̳߳��ύ����
	Result submitTask(std::shared_ptr<Task>sp);

private:
	std::unordered_map<int, std::unique_ptr<Thread>>threads_;       //����̵߳�����
	std::queue < std::shared_ptr<Task> >taskQue_;                    //�������Ķ���

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
	void func(int id);
};