

add_library(ObjectWrap SHARED
        my_object.cpp
        object_wrap.cpp)

AddNapiSupport(ObjectWrap)


set_target_properties(ObjectWrap PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
