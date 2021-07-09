cmake_minimum_required(VERSION 3.19)
project(NapiExample)

set(CMAKE_CXX_STANDARD 20)

include(cmake/napi.cmake)

add_subdirectory(1_hello_world)

add_subdirectory(2_function_arguments)
add_subdirectory(3_callbacks)
add_subdirectory(4_object_factory)
add_subdirectory(5_function_factory)
add_subdirectory(6_object_wrap)
add_subdirectory(7_factory_wrap)
add_subdirectory(8_passing_wrapped)
