#ifndef CORE_LOGGER_IMPL_H
#define CORE_LOGGER_IMPL_H

#include <mutex>

namespace core
{
    class logger_impl
    {
    public:
        static logger_impl& get();
        std::unique_lock<std::mutex> get_mutex();

    public:
        logger_impl(const logger_impl&) = delete;
        logger_impl& operator=(const logger_impl&) = delete;
        logger_impl(logger_impl&&) = delete;
        logger_impl& operator=(logger_impl&&) = delete;

    private:
        logger_impl() = default;
        ~logger_impl() = default;

    private:
        static std::mutex sMutex;
    };
} // namespace core

#endif // CORE_LOGGER_IMPL_H
