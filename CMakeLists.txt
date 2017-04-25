if( ${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR}/build )
else()
	message( FATAL_ERROR "Dear student, you just tried to launch"
	" cmake in another directory than build/. We encourage you to"
	" be more careful in the future and NEVER DO THAT AGAIN. Now "
	"the build system will stop, and you will remove "
	"../CMakeCache.txt and ../CMakefiles/.\n--Your 3D Computer Graphics teachers.")
endif()

#==========================================
#Project options
#==========================================
cmake_minimum_required(VERSION 2.8)

#==========================================
#Project name
#==========================================
project(CPP)



#==========================================
#Building options
#==========================================
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

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
