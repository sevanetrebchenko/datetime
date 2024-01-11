# `datetime`

## Overview
`datetime` is a simple C++ library for working with timestamps, dates, and the durations between them (to millisecond precision).

## Building
This project is built using CMake, and requires a compiler that supports C++11 (or higher). Use the following example to include `datetime` into your project's build tree:
```cmake
project(YOUR_PROJECT_NAME ...)
...
add_subdirectory(lib/datetime) # Path to datetime root directory.
target_link_libraries(YOUR_PROJECT_NAME datetime)
```

## Sample Usage
```c++
#include "datetime/timestamp.hpp"
#include <iostream> // std::cout
#include <iomanip> // std::setw, std::setfill

int main() {
    using namespace datetime;
    Timestamp now = Timestamp::now();
    
    std::cout << "today's date is ";
    std::cout << std::setw(2) << std::setfill('0') << (int) now.date.month;
    std::cout << "/";
    std::cout << std::setw(2) << std::setfill('0') << (int) now.date.day;
    std::cout << "/";
    std::cout << now.date.year;
    std::cout << "\n";
    
    // Time is in UTC by default, must be adjusted for timezones.
    std::cout << "the current time is ";
    std::cout << std::setw(2) << std::setfill('0') << now.time.hour << ":";
    std::cout << std::setw(2) << std::setfill('0') << (int) now.time.minute << ":";
    std::cout << std::setw(2) << std::setfill('0') << (int) now.time.second;
    std::cout << " UTC";
    std::cout << "\n";
    
    // Calculate the duration of time since the start of 2024.
    Timestamp start = Timestamp(January, 01, 2024); // or Timestamp start = Timestamp(01, 01, 2024);
    Duration duration = now - start;
    
    std::cout << "time since 00:00 January 1st, 2024: ";
    std::cout << duration.days << " day(s), ";
    std::cout << (int) duration.hours << " hour(s), ";
    std::cout << (int) duration.minutes << " minute(s), ";
    std::cout << (int) duration.seconds << " second(s), ";
    std::cout << (int) duration.milliseconds << " millisecond(s)";
    std::cout << "\n";
    
    return 0;
}
```

Sample output:
```c++
today's date is 01/11/2024
the current time is 10:36:22 UTC
time since 00:00 January 1st, 2024: 10 day(s), 10 hour(s), 36 minute(s), 22 second(s), 321 millisecond(s)
```

## License
The source code for this project is licensed under the MIT license, which can be found in the [LICENSE.txt](https://github.com/sevanetrebchenko/datetime/blob/master/LICENSE.txt) file.
