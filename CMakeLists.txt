cmake_minimum_required(VERSION 3.3)
project(datetime VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library("${PROJECT_NAME}" STATIC
    "${PROJECT_SOURCE_DIR}/src/date.cpp"
    "${PROJECT_SOURCE_DIR}/src/duration.cpp"
    "${PROJECT_SOURCE_DIR}/src/time.cpp"
    "${PROJECT_SOURCE_DIR}/src/timestamp.cpp"
)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_SOURCE_DIR}/include")
