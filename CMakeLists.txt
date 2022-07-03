cmake_minimum_required(VERSION 3.12)
project(SquirrelTest CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES main.cpp)
set(HEADERS )

set(INCLUDES  ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/lib/squirrel.lib
              ${CMAKE_CURRENT_SOURCE_DIR}/lib/sqstdlib.lib)

add_executable(SquirrelTest ${HEADERS} ${SOURCES})

target_link_libraries(SquirrelTest PUBLIC ${LIBRARIES})
target_include_directories(SquirrelTest PRIVATE ${INCLUDES})