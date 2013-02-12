PROJECT(FHLIB)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


#-------------------------------------------------------------------------------
# General Settings
#-------------------------------------------------------------------------------
SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS "-Wall -Wextra")
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

ADD_DEFINITIONS(-DENABLE_PROFILING)

#-------------------------------------------------------------------------------
# Include sources
#-------------------------------------------------------------------------------
SET(LIBRARY_SOURCES
  src/Timer.cpp
  src/Verbose.cpp
  src/Debugger.hpp
)


#-------------------------------------------------------------------------------
# Define executable and link libraries
#-------------------------------------------------------------------------------
ADD_EXECUTABLE(timer ${LIBRARY_SOURCES} tests/timer.cpp)
TARGET_LINK_LIBRARIES(timer -lrt)


#-------------------------------------------------------------------------------
# Status report
#-------------------------------------------------------------------------------
MESSAGE(STATUS " Compiling mode is '${CMAKE_BUILD_TYPE}'")
