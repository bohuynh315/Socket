#ifndef CORE_LOGGER_H
#define CORE_LOGGER_H

#include <sstream>

namespace core
{
    enum class log_level_t {
        NONE = 0,
        FATAL = 1,
        ERROR = 2,
        WARNING = 3,
        INFO = 4,
        DEBUG = 5,
        VERBOSE = 6
    };

    class Logger
    {
    public:
        Logger(const log_level_t level);
        virtual ~Logger();

        Logger& begin();

        template<typename T>
        Logger& operator<<(const T& msg)
        {
            mStream << msg;
            return *this;
        }
    
    private:
        log_level_t mLevel;
        std::stringstream mStream;
    };
}

#define LOG_FATAL   core::Logger(core::log_level_t::FATAL).begin() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "
#define LOG_ERROR   core::Logger(core::log_level_t::ERROR).begin() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "
#define LOG_WARNING core::Logger(core::log_level_t::WARNING).begin() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "
#define LOG_INFO    core::Logger(core::log_level_t::INFO).begin() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "
#define LOG_DEBUG   core::Logger(core::log_level_t::DEBUG).begin() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "
#define LOG_VERBOSE core::Logger(core::log_level_t::VERBOSE).begin() << "[" << __FUNCTION__ << "][" << __LINE__ << "] "

#endif // CORE_LOGGER_H
