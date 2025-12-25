project(core VERSION 1.0 LANGUAGES CXX)

file(GLOB_RECURSE CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(core STATIC ${CORE_SOURCES})

# target_link_libraries(core PUBLIC
#     glfw3
# )

target_link_directories(core PUBLIC
    ${CMAKE_SOURCE_DIR}/build/core/vendor/glfw/src
)

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include
)

# Vendor
add_subdirectory(vendor/glfw)
