cmake_minimum_required(VERSION 3.20)
project(OOD1)
set(CMAKE_CXX_STANDARD 20)

include(conan_libraries/conan_paths.cmake)
find_package(GTest)

add_library(${PROJECT_NAME}_objs
        src/All.hpp
        src/empty.cpp)

##dont delete this line
#set_target_properties(${PROJECT_NAME}_objs PROPERTIES LINKER_LANGUAGE CXX)

#Unit Tests
include(GoogleTest)
add_executable( ${PROJECT_NAME}_tests
        tests/basic.cpp
        )
target_link_libraries(${PROJECT_NAME}_tests PRIVATE
        GTest::gtest
        GTest::gtest_main
        ${PROJECT_NAME}_objs)
#Main
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_objs)

include_directories(src)