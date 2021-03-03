cmake_minimum_required(VERSION 3.17)
project(data_structures_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories("Header Files")

add_executable(data_structures_algorithms
        "Header Files/ExtendedTest.h"
        "Header Files/ShortTest.h"
        "Header Files/SortedBag.h"
        "Header Files/SortedBagIterator.h"
        "Source Files/App.cpp"
        "Source Files/ExtendedTest.cpp"
        "Source Files/ShortTest.cpp"
        "Source Files/SortedBag.cpp"
        "Source Files/SortedBagIterator.cpp")
