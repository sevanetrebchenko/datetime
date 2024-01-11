
#include "datetime/timestamp.hpp"

namespace datetime {
    
    Timestamp Timestamp::now() {
        return { };
    }
    
    Timestamp::Timestamp() : date(),
                             time()
                             {
    }
    
    Timestamp::Timestamp(std::uint8_t month, std::uint8_t day, std::uint32_t year, std::uint32_t hour, std::uint32_t minute, std::uint32_t second, std::uint32_t millisecond) : date(month, day, year),
                                                                                                                                                                                time(hour, minute, second, millisecond)
                                                                                                                                                                                {
    }
    
    Timestamp::~Timestamp() = default;
    
    Duration Timestamp::operator-(const Timestamp& other) const {
        if (*this == other) {
            return { };
        }
        
        Timestamp start, end;
        
        if (*this > other) {
            start = other;
            end = *this;
        }
        else {
            start = *this;
            end = other;
        }
        
        unsigned days = end.date.count_days() - start.date.count_days();
        unsigned hours = 0u;
        unsigned minutes = 0u;
        unsigned seconds = 0u;
        unsigned milliseconds = 0u;
        
        if (end.time.hour >= start.time.hour) {
            hours = end.time.hour - start.time.hour;
        }
        else {
            days -= 1u;
            hours = (24u + end.time.hour) - start.time.hour;
        }
        
        if (end.time.minute >= start.time.minute) {
            minutes = end.time.minute - start.time.minute;
        }
        else {
            hours -= 1u;
            minutes = (60u + end.time.minute) - start.time.minute;
        }
        
        if (end.time.second >= start.time.second) {
            seconds = end.time.second - start.time.second;
        }
        else {
            minutes -= 1u;
            seconds = (60u + end.time.second) - start.time.second;
        }
        
        if (end.time.millisecond >= start.time.millisecond) {
            milliseconds = end.time.millisecond - start.time.millisecond;
        }
        else {
            seconds -= 1u;
            milliseconds = (1000u + end.time.millisecond) - start.time.millisecond;
        }
        
        return { milliseconds, seconds, minutes, hours, days };
    }
    
    bool Timestamp::operator==(const Timestamp& other) const {
        return date == other.date && time == other.time;
    }
    
    bool Timestamp::operator<(const Timestamp& other) const {
        return date < other.date && time < other.time;
    }
    
    bool Timestamp::operator<=(const Timestamp& other) const {
        return date <= other.date && time <= other.time;
    }
    
    bool Timestamp::operator>(const Timestamp& other) const {
        return date > other.date && time > other.time;
    }
    
    bool Timestamp::operator>=(const Timestamp& other) const {
        return date >= other.date && time >= other.time;
    }
    
}