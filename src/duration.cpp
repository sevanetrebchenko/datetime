
#include "datetime/duration.hpp"

namespace datetime {
    
    Duration::Duration(std::uint32_t ms, std::uint32_t s, std::uint32_t m, std::uint32_t h, std::uint32_t d) {
        s += ms / 1000u;
        milliseconds = ms % 1000u;
        
        m += s / 60u;
        seconds = s % 60u;
        
        h += m / 60u;
        minutes = m % 60u;
        
        d += h / 24u;
        hours = h % 24u;
        
        days = d;
    }
    
    Duration::~Duration() = default;
    
}