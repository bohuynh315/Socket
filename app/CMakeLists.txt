add_executable(Server Server/server_main.cpp)

target_link_libraries(Server PRIVATE core)

target_include_directories(Server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../core)

set_target_properties(Server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)

add_executable(Client Client/client_main.cpp)

target_link_libraries(Client PRIVATE core)

target_include_directories(Client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../core)

set_target_properties(Client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)
