
#include "datetime/time.hpp"
#include <chrono> // std::chrono::time_point, std::chrono::system_clock
#include <stdexcept> // std::runtime_error

namespace datetime {
    
    Time Time::now() {
        return { };
    }
    
    Time::Time() {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        std::time_t time_point = std::chrono::system_clock::to_time_t(now);
        std::tm time { }; // UTC
        gmtime_s(&time, &time_point);
        
        hour = static_cast<std::uint32_t>(time.tm_hour);
        minute = static_cast<std::uint8_t>(time.tm_min);
        second = static_cast<std::uint8_t>(time.tm_sec);
        millisecond = static_cast<std::uint16_t>(std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch() % std::chrono::seconds(1)).count());
    }
    
    Time::Time(std::uint32_t hour, std::uint32_t minute, std::uint32_t second, std::uint32_t millisecond) : hour(hour),
                                                                                                            minute(minute),
                                                                                                            second(second),
                                                                                                            millisecond(millisecond)
                                                                                                            {
        if (hour > 23u) {
            throw std::runtime_error("invalid hour value - must be in range [0, 23]");
        }
        
        if (minute > 59u) {
            throw std::runtime_error("invalid minute value - must be in range [0, 59]");
        }
        
        if (second > 59u) {
            throw std::runtime_error("invalid second value - must be in range [0, 59]");
        }
        
        if (millisecond > 999u) {
            throw std::runtime_error("invalid millisecond value - must be in range [0, 999]");
        }
    }
    
    Time::~Time() = default;
    
    Duration Time::operator-(const Time& other) const {
        if (*this == other) {
            return { };
        }
        
        Time start, end;
        if (*this > other) {
            start = other;
            end = *this;
        }
        else {
            start = *this;
            end = other;
        }
        
        unsigned h = end.hour - start.hour;
        unsigned m;
        unsigned s;
        unsigned ms;
        
        if (end.minute >= start.minute) {
            m = end.minute - start.minute;
        }
        else {
            h -= 1u;
            m = (60u + end.minute) - start.minute;
        }
        
        if (end.second >= start.second) {
            s = end.second - start.second;
        }
        else {
            m -= 1u;
            s = (60u + end.second) - start.second;
        }
        
        if (end.millisecond >= start.millisecond) {
            ms = end.millisecond - start.millisecond;
        }
        else {
            s -= 1u;
            ms = (1000u + end.millisecond) - start.millisecond;
        }
        
        return { ms, s, m, h, 0u };
    }
    
    bool Time::operator==(const Time& other) const {
        return hour == other.hour && minute == other.minute && second == other.second && millisecond == other.millisecond;
    }
    
    bool Time::operator>(const Time& other) const {
        return hour > other.hour || minute > other.minute || second > other.second || millisecond > other.millisecond;
    }
    
    bool Time::operator<(const Time& other) const {
        return hour < other.hour || minute < other.minute || second < other.second || millisecond < other.millisecond;
    }
    
    bool Time::operator>=(const Time& other) const {
        return hour >= other.hour || minute >= other.minute || second >= other.second || millisecond >= other.millisecond;
    }
    
    bool Time::operator<=(const Time& other) const {
        return hour <= other.hour || minute <= other.minute || second <= other.second || millisecond <= other.millisecond;
    }
    
}