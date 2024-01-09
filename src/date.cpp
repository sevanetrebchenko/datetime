
#include "datetime/date.hpp"
#include <chrono>

namespace datetime {
    
    [[nodiscard]] bool is_leap_year(unsigned year) {
        return (year % 400 == 0u) || (year % 4u == 0u && year % 100u != 0u);
    }
    
    Date Date::today() {
        return { };
    }
    
    Date::Date() {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        std::time_t time_point = std::chrono::system_clock::to_time_t(now);
        std::tm time { }; // UTC
        gmtime_s(&time, &time_point);
        
        day = static_cast<std::uint8_t>(time.tm_mday);
        month = static_cast<std::uint8_t>(time.tm_mon + 1);
        year = static_cast<std::uint32_t>(time.tm_year + 1900);
        
        // std::tm::tm_wday - days since Sunday, 0 - 6 (https://en.cppreference.com/w/cpp/chrono/c/tm)
        weekday = static_cast<Weekday>((time.tm_wday + 6) % 7);
    }
    
    Date::Date(std::uint8_t m, std::uint8_t d, std::uint32_t y) {
        if (m == 0u) {
            throw std::runtime_error("invalid month - month must be in range [1, 12]");
        }
        
        bool leap = is_leap_year(y);
        if ((d == 0u) || (m == 1u && d > 31) || (m == 2u && (leap && d > 29) || (!leap && d > 28)) || (m == 3u && d > 31) ||
            (m == 4u && d > 30) || (m == 5u && d > 31) || (m == 6u && d > 30) || (m == 7u && d > 31) || (m == 8u && d > 31) ||
            (m == 9u && d > 30) || (m == 10u && d > 31) || (m == 11u && d > 30) || (m == 12u && d > 31)) {
            throw std::runtime_error("invalid day");
        }
        
        year = y;
        month = m;
        day = d;
        
        // Calculating the day of the week: https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/
        unsigned yy = y % 100;
        unsigned yc = (yy + (yy / 4)) % 7;
        const int mcs[12] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
        unsigned mc = mcs[m - 1];
        
        // Returns if value is in range [min, max)
        auto in_range = [](unsigned value, unsigned min, unsigned max) -> bool {
            return value >= min && value < max;
        };
        
        const int ccs[4] = { 6, 4, 2, 0 };
        unsigned cc = ccs[static_cast<unsigned>(y / 100) % 4u];
        
        unsigned lyc = leap && (m == 1u || m == 2u) ? 1u : 0u;
        weekday = static_cast<Weekday>(((yc + mc + cc + d - lyc) % 7 + 6) % 7);
    }

    Date::~Date() = default;
    
    Duration Date::operator-(const Date& other) const {
        return false;
    }
    
    bool Date::operator==(const Date& other) const {
        return false;
    }
    
    bool Date::operator>(const Date& other) const {
        return false;
    }
    
    bool Date::operator<(const Date& other) const {
        return false;
    }
    
    bool Date::operator>=(const Date& other) const {
        return false;
    }
    
    bool Date::operator<=(const Date& other) const {
        return false;
    }
    
}