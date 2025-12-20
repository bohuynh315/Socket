#ifndef CORE_TIMESTAMP_H
#define CORE_TIMESTAMP_H

#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

namespace core
{
    class timestamp
    {
    public:
        timestamp()
        {
            mTimePoint = std::chrono::system_clock::now();
        }

        std::string get()
        {
            std::time_t time = std::chrono::system_clock::to_time_t(mTimePoint);
            std::tm tm = *std::localtime(&time);
            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        }

    private:
        std::chrono::system_clock::time_point mTimePoint;
    };
} // namespace core

#endif // CORE_TIMESTAMP_H
