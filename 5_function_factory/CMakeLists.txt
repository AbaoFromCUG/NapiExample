

add_library(FunctionFactory SHARED function_factory.cpp)

AddNapiSupport(FunctionFactory)


set_target_properties(FunctionFactory PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
