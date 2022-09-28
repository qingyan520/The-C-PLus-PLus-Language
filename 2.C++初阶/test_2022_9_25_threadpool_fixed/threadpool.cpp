#pragma once
#include"threadpool.h"

std::atomic_int Thread::ID = 0;
Result::Result(std::shared_ptr<Task> s, bool isSet) :task_(s), isSet_(isSet)
{
	task_->setRes(this);
}

void Result::SetVal(Any val) {
	//cout << "id:" << std::this_thread::get_id() << "ִ��Result::SetVal" << endl;
	this->any_ = std::move(val);
	sem_.post();
}

Any Result::get()
{
	if (isSet_ == false)
	{
		return "";
	}
//	cout << "[" << std::this_thread::get_id() << "]" << " :Any::Result::get()" << endl;
	sem_.wait();
	//cout << "any:" << any_.get_cast<double>() << endl;
	//cout << "[" << std::this_thread::get_id() << "]" << " :Any::Result::get() success" << endl;

	return std::move(any_);
}

void Task::exec()
{
	if (res_ != nullptr)
	{
		//cout << "id:" << std::this_thread::get_id() << "ִ��--exec" << endl;
		res_->SetVal(Run());

		//cout << "id:" << std::this_thread::get_id() << "ִ��--exec----���" << endl;

	}
}
void Task::setRes(Result* res)
{
	res_ = res;
}

//���̳߳��ύ����
Result ThreadPool::submitTask(std::shared_ptr<Task>sp)
{
	std::unique_lock<std::mutex>lock(this->taskMtx_);
	if (Not_Full.wait_for(lock, std::chrono::seconds(3), [&]()->bool {
		return taskQue_.size() < taskQueMaxSize_;
		}) == false)
	{
		LOG(WARNING, "taskQue is full");
		return Result(sp, false);
	}
	
		//���ڻ�ȡ��֮������������������ͬʱ�ж��Ƿ�Ϊcachedģʽ�������cachedģʽ����ô����Ҫ����
		//�жϵ�ǰ�����߳������ǲ���С�����������ͬʱ�߳�����С��cachedģʽ����߳�����

		//������������Ԫ��
		taskQue_.push(sp);
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
		return Result(sp);
}

//�̴߳�������
void ThreadPool::func(int id)
{
	
	//���ÿ���߳����һ�η���ʱ��
	auto LastTime =std::chrono::high_resolution_clock::now();
	for (;;)
	{
	
		cout << std::this_thread::get_id() << ":taskQueSIze:" << taskQue_.size() << endl;
		std::shared_ptr<Task>task=nullptr;

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
						cout<<std::this_thread::get_id() <<" " << curThreadSize_ << " " << threadInitSize_ << endl;
						if (mul.count() >= 3 && curThreadSize_ > threadInitSize_)
						{
							cout <<"ɱ���߳�" << std::this_thread::get_id() << " " << curThreadSize_ << " " << threadInitSize_ << endl;
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

		if (task != nullptr)
		{
			//cout << std::this_thread::get_id() << " ִ������" << endl;
			task->exec();
		}

		freeThreadSize_++;
		LastTime= std::chrono::high_resolution_clock::now(); //�����߳����һ�η���ʱ��
	}

}