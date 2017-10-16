cmake_minimum_required(VERSION 3.1)
project(oanda-trading)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(OANDA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/oanda-trading/src)

set(BUILD_CPR_TESTS OFF CACHE BOOL "Don't build cpr tests")
set(BUILD_OANDA_EXEC OFF CACHE BOOL "Don't build oanda exec")
set(BUILD_OANDA_TESTS OFF CACHE BOOL "Don't build oanda tests")

add_subdirectory(include/oanda-trading)

include_directories(
    ${CATCH_INCLUDE_DIR}
    ${RANGEV3_INCLUDE_DIR}
    ${FMT_INCLUDE_DIR}
    ${CPR_INCLUDE_DIRS}
    ${JSON_INCLUDE_DIRS}
    ${OANDA_INCLUDE_DIR}
  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
add_executable(main main.cc)
target_link_libraries(main ${CPR_LIBRARIES})
