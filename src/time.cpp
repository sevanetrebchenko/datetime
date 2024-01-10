
#include "datetime/time.hpp"
#include <chrono>

namespace datetime {
    
    Time Time::now() {
        return { };
    }
    
    Time::Time() : hours(0u),
                   minutes(0u),
                   seconds(0u),
                   milliseconds(0u)
                   {
    }
    
    Time::Time(std::uint32_t ms, std::uint32_t s, std::uint32_t m, std::uint32_t h) {
        s += ms / 1000u;
        milliseconds = ms % 1000u;
        
        m += s / 60u;
        seconds = s % 60u;
        
        h += m / 60u;
        minutes = m % 60u;
        
        hours = h;
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
        
        unsigned h = end.hours - start.hours;
        unsigned m;
        unsigned s;
        unsigned ms;
        
        if (end.minutes >= start.minutes) {
            m = end.minutes - start.minutes;
        }
        else {
            h -= 1u;
            m = (60u + end.minutes) - start.minutes;
        }
        
        if (end.seconds >= start.seconds) {
            s = end.seconds - start.seconds;
        }
        else {
            m -= 1u;
            s = (60u + end.seconds) - start.seconds;
        }
        
        if (end.milliseconds >= start.milliseconds) {
            ms = end.milliseconds - start.milliseconds;
        }
        else {
            s -= 1u;
            ms = (1000u + end.milliseconds) - start.milliseconds;
        }
        
        return { ms, s, m, h, 0u };
    }
    
    bool Time::operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds && milliseconds == other.milliseconds;
    }
    
    bool Time::operator>(const Time& other) const {
        return hours > other.hours || minutes > other.minutes || seconds > other.seconds || milliseconds > other.milliseconds;
    }
    
    bool Time::operator<(const Time& other) const {
        return hours < other.hours || minutes < other.minutes || seconds < other.seconds || milliseconds < other.milliseconds;
    }
    
    bool Time::operator>=(const Time& other) const {
        return hours >= other.hours || minutes >= other.minutes || seconds >= other.seconds || milliseconds >= other.milliseconds;
    }
    
    bool Time::operator<=(const Time& other) const {
        return hours <= other.hours || minutes <= other.minutes || seconds <= other.seconds || milliseconds <= other.milliseconds;
    }
    
}