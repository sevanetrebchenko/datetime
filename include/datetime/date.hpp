
#ifndef DATETIME_DATE_HPP
#define DATETIME_DATE_HPP

#include "datetime/duration.hpp"
#include <cstdint>

namespace datetime {
    
    enum class Weekday {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    
    struct Date {
        static Date today();
        
        Date(); // Returns the current date, equivalent to calling Date::today().
        Date(std::uint8_t day, std::uint8_t month, std::uint32_t year);
        ~Date();
        
        Duration operator-(const Date& other) const;
        
        bool operator==(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>=(const Date& other) const;
        bool operator<=(const Date& other) const;
        
        std::uint32_t year;
        std::uint8_t month; // ranges from 1 to 12
        std::uint8_t day; // ranges from 1 to 31
        Weekday weekday;
    };
    
}

#endif // DATETIME_DATE_HPP
