add_executable(Server server.cpp)

target_link_libraries(Server PRIVATE core)

target_include_directories(Server PRIVATE 
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/core/interface
)

set_target_properties(Server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
