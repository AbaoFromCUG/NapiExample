

add_library(PassingWrapped SHARED
        my_object.cpp
        passing_wrapped.cpp)

AddNapiSupport(PassingWrapped)


set_target_properties(PassingWrapped PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
