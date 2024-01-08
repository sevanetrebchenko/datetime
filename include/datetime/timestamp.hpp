
#ifndef DATETIME_TIMESTAMP_HPP
#define DATETIME_TIMESTAMP_HPP

#include "datetime/date.hpp"
#include "datetime/time.hpp"
#include "datetime/timestamp.hpp"
#include <cstdint>

namespace datetime {
    
    struct Timestamp {
        static Timestamp now();

        Timestamp() = delete;
        ~Timestamp();
        
        bool operator==(const Timestamp& other) const;
        bool operator<(const Timestamp& other) const;
        bool operator<=(const Timestamp& other) const;
        bool operator>(const Timestamp& other) const;
        bool operator>=(const Timestamp& other) const;
        
        Duration operator-(const Timestamp& other) const;
        
        Date date;
        Time time;
    };
    
}

#endif // DATETIME_TIMESTAMP_HPP
