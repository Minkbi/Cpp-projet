cmake_minimum_required (VERSION 2.8.11)

project(Demo)

set(CMAKE_CXX_FLAGS "-g -Wall")
=======
#==========================================
#Project name
#==========================================
project(CPP)

add_test (NAME test_gtest COMMAND test_simple)
#add_test (NAME test_class_gtest COMMAND test_class)
=======
#==============================================
#Project sources : src
#==============================================
file(
    GLOB_RECURSE
    HEADER_FILES
    src/*.h
    )

file(
    GLOB_RECURSE
    SOURCE_FILES
    src/*.cpp
    )

set(EXECUTABLE_NAME main)

#==============================================
#Project executable definition
#==============================================
add_executable(${EXECUTABLE_NAME} ${HEADER_FILES} ${SOURCE_FILES} ${SHADER_FILES})

message( "The build type is set to " ${CMAKE_BUILD_TYPE})

