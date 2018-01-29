cmake_minimum_required(VERSION 3.8)
project(cmpe126s18_labs)

if(WIN32)
    if (CYGWIN)
        add_definitions(-std=gnu++0x)
    elseif(MINGW)
        add_definitions(-std=c++11)
    endif(CYGWIN)
elseif(APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif(WIN32)

set(SOURCE_FILES main.cpp)

add_executable(labs_main ${SOURCE_FILES})

include_directories(lib/lab01/inc)

add_subdirectory(lib/lab01 lab1_lib)

add_subdirectory(test)

target_link_libraries(labs_main lab1_lib)