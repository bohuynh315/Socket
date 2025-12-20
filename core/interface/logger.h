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

    class logger
    {
    public:
        logger(const log_level_t level);
        virtual ~logger();

        logger& begin();

        template<typename T>
        logger& operator<<(const T& msg)
        {
            mStream << msg;
            return *this;
        }
    
    private:
        log_level_t mLevel;
        std::stringstream mStream;
    };
}

#define LOG_FATAL   core::logger(core::log_level_t::FATAL).begin()
#define LOG_ERROR   core::logger(core::log_level_t::ERROR).begin()
#define LOG_WARNING core::logger(core::log_level_t::WARNING).begin()
#define LOG_INFO    core::logger(core::log_level_t::INFO).begin()
#define LOG_DEBUG   core::logger(core::log_level_t::DEBUG).begin()
#define LOG_VERBOSE core::logger(core::log_level_t::VERBOSE).begin()

#endif // CORE_LOGGER_H
