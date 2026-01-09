#include "ThreadPool.h"

namespace core
{
    ThreadPool::ThreadPool()
        : mStop(false)
    {
        size_t threadCount = std::thread::hardware_concurrency();
        for (size_t i = 0; i < threadCount; ++i) {
            mThreads.emplace_back([this]() {
                this->worker_thread(); 
            });
        }
    }

    ThreadPool::~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mStop = true;
        }

        mCondition.notify_all();
        for (std::thread &worker : mThreads) {
            if (worker.joinable()) {
                worker.join();
            }
        }
    }

    void ThreadPool::enqueue_task(const task_handler_t& task)
    {
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mTasks.emplace(task);
        }
        mCondition.notify_one();
    }

    void ThreadPool::worker_thread()
    {
        while (true) {
            task_handler_t task;
            {
                std::unique_lock<std::mutex> lock(mMutex);
                mCondition.wait(lock, [this]() { return mStop || !mTasks.empty(); });

                if (mStop && mTasks.empty()) {
                    return;
                }

                task = std::move(mTasks.front());
                mTasks.pop();
            }
            task();
        }
    }
} // namespace core
