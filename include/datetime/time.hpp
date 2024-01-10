
#ifndef DATETIME_TIME_HPP
#define DATETIME_TIME_HPP

#include "datetime/duration.hpp"
#include <cstdint>

namespace datetime {
    
    struct Time {
        static Time now();
        
        Time(); // Returns the current time, equivalent to calling Time::now().
        Time(std::uint32_t hours, std::uint32_t minutes, std::uint32_t seconds = 0u, std::uint32_t milliseconds = 0u); // Automatically converts on overflow.
        ~Time();
        
        Duration operator-(const Time& other) const;
        
        bool operator==(const Time& other) const;
        bool operator>(const Time& other) const;
        bool operator<(const Time& other) const;
        bool operator>=(const Time& other) const;
        bool operator<=(const Time& other) const;
        
        std::uint32_t hours;
        std::uint8_t minutes; // ranges from 0 to 59
        std::uint8_t seconds; // ranges from 0 to 59
        std::uint16_t milliseconds; // ranges from 0 to 999
    };

}

#endif // DATETIME_TIME_HPP
