cmake_minimum_required(VERSION 3.10)

project(rk_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)

# Найти GTest
find_package(GTest REQUIRED)
if (TARGET GTest::gtest)
  message(STATUS "GTest found")
else()
  message(FATAL_ERROR "GTest not found. Install GTest or use FetchContent.")
endif()

# Исполняемый файл
add_executable(rk_2 ./source/main.cpp) 
target_link_libraries(rk_2 GTest::gtest GTest::gtest_main)
