#include "logger.h"

#include <iostream>
#include <thread>

#include "logger_impl.h"
#include "timestamp.h"

namespace core
{
    Logger::Logger(const log_level_t level)
        : mLevel(level)
    {

    }

    Logger::~Logger()
    {
        std::unique_lock<std::mutex> lock = LoggerImpl::get().get_mutex();
        std::cout << mStream.str() << std::endl;
    }

    Logger &Logger::begin()
    {
        mStream << "[";

        switch (mLevel)
        {
        case log_level_t::FATAL:
            mStream << "FATAL";
            break;
        case log_level_t::ERROR:
            mStream << "ERROR";
            break;
        case log_level_t::WARNING:
            mStream << "WARNING";
            break;
        case log_level_t::INFO:
            mStream << "INFO";
            break;
        case log_level_t::DEBUG:
            mStream << "DEBUG";
            break;
        case log_level_t::VERBOSE:
            mStream << "VERBOSE";
            break;
        default:
            mStream << "NONE";
            break;
        }

        TimeStamp ts;
        mStream << "][" << std::this_thread::get_id() << "][" << ts.get() << "]";
        return *this;
    }
} // namespace core
