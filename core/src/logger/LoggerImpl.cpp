#include "LoggerImpl.h"

namespace core
{
    std::mutex LoggerImpl::sMutex;

    LoggerImpl& LoggerImpl::get()
    {
        static LoggerImpl instance;
        return instance;
    }

    std::unique_lock<std::mutex> LoggerImpl::get_mutex()
    {
        return std::unique_lock<std::mutex>(sMutex);
    }
} // namespace core
