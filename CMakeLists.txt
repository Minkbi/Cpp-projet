cmake_minimum_required (VERSION 2.8.11)

project(Demo)

set(CMAKE_CXX_FLAGS "-g -Wall")

#==========================================
#Project name
#==========================================
project(CPP)

add_test (NAME test_gtest COMMAND test_simple)
#add_test (NAME test_class_gtest COMMAND test_class)

#==========================================
#Building options
#==========================================
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -lGL -lglut -lGLU -lpng -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

#==========================================
#Libraries path : glut glm, sfml, glew, opengl, freetype
#==========================================

#GLUT Libraries
set(GLM_INCLUDE_DIRS "GL/glut.h" CACHE PATH "glut")
include_directories(${GLM_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

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

