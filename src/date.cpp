
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
    }

    Date::~Date() = default;
    
    std::uint32_t Date::count_days() const {
        unsigned count = 0u;
        
        for (unsigned y = 0u; y < year; ++y) {
            count += is_leap_year(y) ? 366u : 365u;
        }
        
        // Zero-based (January = 0)
        const int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        for (unsigned m = 0u; m < month - 1u; ++m) {
            count += days_per_month[m];
        }
        
        return count + day;
    }
    
    // The result of this function is not cached as a member of Date since the user has direct access to the member variables.
    Weekday Date::weekday() const {
        // Calculating the day of the week: https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/
        unsigned yy = year % 100;
        unsigned yc = (yy + (yy / 4)) % 7;
        static const int mcs[12] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
        unsigned mc = mcs[month - 1];
        
        static const int ccs[4] = { 6, 4, 2, 0 };
        unsigned cc = ccs[static_cast<unsigned>(year / 100) % 4u];
        
        unsigned lyc = is_leap_year(year) && (month == 1u || month == 2u) ? 1u : 0u;
        return static_cast<Weekday>(((yc + mc + cc + day - lyc) % 7 + 6) % 7);
    }
    
    Duration Date::operator-(const Date& other) const {
        std::uint32_t d1 = count_days();
        std::uint32_t d2 = other.count_days();
        
        // Duration is absolute.
        return { 0u, 0u, 0u, 0u, d1 > d2 ? d1 - d2 - 1u : d2 - d1 - 1u };
    }
    
    bool Date::operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }
    
    bool Date::operator>(const Date& other) const {
        return year > other.year || month > other.month || day > other.day;
    }
    
    bool Date::operator<(const Date& other) const {
        return year < other.year || month < other.month || day < other.day;
    }
    
    bool Date::operator>=(const Date& other) const {
        return year >= other.year || month >= other.month || day >= other.day;
    }
    
    bool Date::operator<=(const Date& other) const {
        return year <= other.year || month <= other.month || day <= other.day;
    }
    
}