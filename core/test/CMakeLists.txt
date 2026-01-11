cmake_minimum_required(VERSION 3.10)
project(TestAPI VERSION 1.0 LANGUAGES CXX)

add_executable(TestAPI test.cpp)

target_link_libraries(TestAPI PUBLIC
    glfw3
    imgui
)

target_link_directories(TestAPI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/lib
)

target_include_directories(TestAPI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/include
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