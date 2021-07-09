

add_library(FactoryWrap SHARED
        my_object.cpp
        factory_wrap.cpp)

AddNapiSupport(FactoryWrap)

set_target_properties(FactoryWrap PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
        )
