

add_library(Callbacks SHARED callbacks.cpp)

AddNapiSupport(Callbacks)


set_target_properties(Callbacks PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
