project(core VERSION 1.0 LANGUAGES CXX)

file(GLOB_RECURSE CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(core STATIC ${CORE_SOURCES})

target_precompile_headers(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include/glad/gl.h
)

target_link_libraries(core PUBLIC
    glfw3
)

target_link_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/lib
)

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/include
)

if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(CORE_FOUNDATION_LIBRARY CoreFoundation)
    find_library(FOUNDATION_LIBRARY Foundation)
    find_library(METAL_LIBRARY Metal)
    find_library(QUARTZCORE_LIBRARY QuartzCore)

    target_link_libraries(${PROJECT_NAME} PUBLIC
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${CORE_FOUNDATION_LIBRARY}
        ${FOUNDATION_LIBRARY}
        ${METAL_LIBRARY}
        ${QUARTZCORE_LIBRARY}
        objc
    )
endif()
