# NAPI stuff

# Use provided python interpreter if given.
if(NOT node_interpreter)
    find_program(node_interpreter "node")
endif()
message(STATUS "Found Node interpreter: ${node_interpreter}")


execute_process(COMMAND ${node_interpreter} -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR
        )
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

message(STATUS "Found N-API installation: ${NODE_ADDON_API_DIR}")

function(AddNapiSupport targetName)

    set_target_properties(${targetName} PROPERTIES PREFIX "" SUFFIX ".node")
    message(STATUS "Using N-API for ${targetName}")

    target_include_directories(${targetName} PRIVATE
            ${NODE_ADDON_API_DIR}
            ${CMAKE_JS_INC}
            )
    target_compile_definitions(${targetName} PRIVATE
            NAPI_CPP_EXCEPTIONS
            )

    if (APPLE)
        set_target_properties(${targetName} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
    endif (APPLE)


    if (WIN32)
        target_compile_definitions(${targetName} PRIVATE
                _HAS_EXCEPTIONS=1
                )
    endif ()
endfunction(AddNapiSupport targetName)


