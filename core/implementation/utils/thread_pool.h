#ifndef CORE_THREAD_POOL_H
#define CORE_THREAD_POOL_H

#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>
#include <queue>
#include <atomic>
#include <memory>
#include <future>
#include <mutex>

typedef std::function<void()> task_handler_t;

namespace core
{
    class ThreadPool
    {
    public:
        ThreadPool();
        ~ThreadPool();

        void enqueue_task(const task_handler_t& task);

    private:
        void worker_thread();

    private:
        std::vector<std::thread> mThreads;
        std::queue<task_handler_t> mTasks;
        std::mutex mMutex;
        std::condition_variable mCondition;
        std::atomic<bool> mStop;

    };
} // namespace core

#endif // CORE_THREAD_POOL_H
