cmake_minimum_required(VERSION 3.21)
set (PROJECT_NAME "cb_vs_others_bench")

project(${PROJECT_NAME}
        VERSION 0.1
        DESCRIPTION "Benchmarking Boost Circular Buffer agains Vector and Deque"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS " -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_RELEASE " -O3")

#Threads not found
IF(APPLE)
    set(CMAKE_THREAD_LIBS_INIT "-lpthread")
    set(CMAKE_HAVE_THREADS_LIBRARY 1)
    set(CMAKE_USE_WIN32_THREADS_INIT 0)
    set(CMAKE_USE_PTHREADS_INIT 1)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
ENDIF()

# BOOST STARTS HERE-------------------
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package (Boost REQUIRED)
if(Boost_FOUND)
    message(STATUS "MAIN: FOUND Boost, including and linking...")
    include_directories(${BOOST_ROOT})
else()
    message(STATUS "TESTS: NOT FOUND Boost")
endif()
# BOOST ENDS HERE-------------------


# BENCHMARK STARTS HERE-------------------
find_package(benchmark REQUIRED)
if(benchmark_FOUND)
    message(STATUS "MAIN: FOUND BENCHMARK, including and linking...")
else()
    message(STATUS "MAIN: NOT FOUND BENCHMARK")
endif()
# BENCHMARK ENDS HERE-------------------


add_executable(${PROJECT_NAME}
        main.cpp
        )
target_link_libraries(${PROJECT_NAME}
        ${Boost_LIBRARIES}
        benchmark::benchmark
        )
