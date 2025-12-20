#include "logger_impl.h"

namespace core
{
    std::mutex logger_impl::sMutex;

    logger_impl& logger_impl::get()
    {
        static logger_impl instance;
        return instance;
    }

    std::unique_lock<std::mutex> logger_impl::get_mutex()
    {
        return std::unique_lock<std::mutex>(sMutex);
    }
} // namespace core
