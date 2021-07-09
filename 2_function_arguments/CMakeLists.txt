

add_library(FunctionArguments SHARED function_arguments.cpp)

AddNapiSupport(FunctionArguments)


set_target_properties(FunctionArguments PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
