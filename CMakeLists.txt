cmake_minimum_required(VERSION 3.21)
project(SquirrelTest CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES main.cpp third_party/args.cpp
					 third_party/array.cpp
                     third_party/class.cpp
					 third_party/enum.cpp
					 third_party/function.cpp
					 third_party/instance.cpp
					 third_party/object.cpp
					 third_party/script.cpp
					 third_party/table.cpp
					 third_party/vm.cpp)
					
set(HEADERS )

set(LIBRARIES squirrel sqstdlib simplesquirrel_static_d sq)

add_definitions(-DSQ_SCRIPT_PATH="${CMAKE_CURRENT_SOURCE_DIR}/scripts")

add_executable(SquirrelTest ${HEADERS} ${SOURCES})

target_link_libraries(SquirrelTest PUBLIC ${LIBRARIES})
target_include_directories(SquirrelTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_directories(SquirrelTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)