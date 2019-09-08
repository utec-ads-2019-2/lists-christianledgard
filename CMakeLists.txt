cmake_minimum_required(VERSION 3.14)
project(lists_christianledgard)

set(CMAKE_CXX_STANDARD 17)

add_executable(lists_christianledgard main.cpp mock/mocker.cpp test/tester.cpp)