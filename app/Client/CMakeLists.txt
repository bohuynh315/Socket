add_executable(Client Client.cpp)

target_link_libraries(Client PRIVATE core)

target_include_directories(Client PRIVATE 
    ${CMAKE_SOURCE_DIR}/core
)

set_target_properties(Client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
