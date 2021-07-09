

add_library(HelloWorld SHARED hello.cpp)

AddNapiSupport(HelloWorld)


set_target_properties(HelloWorld PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
