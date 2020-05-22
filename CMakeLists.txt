cmake_minimum_required(VERSION 3.16)
project(chord)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# find library curl and set CURL variable. Cmake will try to find it magic places like /usr/local/lib
find_library(CURL curl)

add_executable(chord main.cpp src/ChordNode.cpp src/ChordNode.h src/utils/NetworkUtils.cpp src/utils/NetworkUtils.h)

# link library
target_link_libraries(chord "${CURL}")

# add header files
target_include_directories(chord PRIVATE ${INCLUDE_DIR})