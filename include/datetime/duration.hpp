
#ifndef DATETIME_DURATION_HPP
#define DATETIME_DURATION_HPP

#include <cstdint> // std::uint8_t, std::uint16_t, std::uint32_t

namespace datetime {
    
    struct Duration {
        Duration(std::uint32_t milliseconds = 0u, std::uint32_t seconds = 0u, std::uint32_t minutes = 0u, std::uint32_t hours = 0u, std::uint32_t days = 0u); // Automatically converts on overflow
        ~Duration();

        std::uint32_t days;
        std::uint8_t hours; // ranges from 0 to 23
        std::uint8_t minutes; // ranges from 0 to 59
        std::uint8_t seconds; // ranges from 0 to 59
        std::uint16_t milliseconds; // ranges from 0 to 999
    };
    
}

#endif // DATETIME_DURATION_HPP
