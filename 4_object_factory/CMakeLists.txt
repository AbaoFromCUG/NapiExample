

add_library(ObjectFactory SHARED object_factory.cpp)

AddNapiSupport(ObjectFactory)


set_target_properties(ObjectFactory PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
