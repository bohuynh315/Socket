#ifndef CORE_LOGGER_IMPL_H
#define CORE_LOGGER_IMPL_H

#include <mutex>

namespace core
{
    class LoggerImpl
    {
    public:
        static LoggerImpl& get();
        std::unique_lock<std::mutex> get_mutex();

    public:
        LoggerImpl(const LoggerImpl&) = delete;
        LoggerImpl& operator=(const LoggerImpl&) = delete;
        LoggerImpl(LoggerImpl&&) = delete;
        LoggerImpl& operator=(LoggerImpl&&) = delete;

    private:
        LoggerImpl() = default;
        ~LoggerImpl() = default;

    private:
        static std::mutex sMutex;
    };
} // namespace core

#endif // CORE_LOGGER_IMPL_H
