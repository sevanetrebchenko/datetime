
#include "datetime/timestamp.hpp"
#include <iostream>
#include <iomanip>

int main() {
    using namespace datetime;
    
    Timestamp now = Timestamp::now();
    std::cout << "today's date is ";
    
    switch (now.date.month) {
        case Month::January:
            std::cout << "January ";
            break;
        case Month::February:
            std::cout << "February ";
            break;
        case Month::March:
            std::cout << "March ";
            break;
        case Month::April:
            std::cout << "April ";
            break;
        case Month::May:
            std::cout << "May ";
            break;
        case Month::June:
            std::cout << "June ";
            break;
        case Month::July:
            std::cout << "July ";
            break;
        case Month::August:
            std::cout << "August ";
            break;
        case Month::September:
            std::cout << "September ";
            break;
        case Month::October:
            std::cout << "October ";
            break;
        case Month::November:
            std::cout << "November ";
            break;
        case Month::December:
            std::cout << "December ";
            break;
    }

    std::cout << static_cast<int>(now.date.day);

    switch (now.date.day) {
        case 1u:
            std::cout << "st";
            break;
        case 2u:
            std::cout << "nd";
            break;
        case 3u:
            std::cout << "rd";
            break;
        default:
            std::cout << "th";
            break;
    }
    
    std::cout << ", " << static_cast<int>(now.date.year);
    std::cout << std::endl;
    
    std::cout << "the time is ";
    std::cout << std::setw(2) << std::setfill('0') << static_cast<int>(now.time.hour) << ":";
    std::cout << std::setw(2) << std::setfill('0') << static_cast<int>(now.time.minute) << ":";
    std::cout << std::setw(2) << std::setfill('0') << static_cast<int>(now.time.second) << ":";
    std::cout << std::setw(3) << std::setfill('0') << static_cast<int>(now.time.millisecond) << " UTC";
    std::cout << std::endl;
    
    return 0;
}