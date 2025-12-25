#include "window_glfw.h"

#include "logger.h"

namespace core
{
    window_glfw::window_glfw(const window_spec &spec)
        : mWindow(nullptr)
    {
        init(spec);
    }

    window_glfw::~window_glfw()
    {

    }

    void window_glfw::init(const window_spec &spec)
    {
        mData.title = spec.mTitle.c_str();
        mData.width = spec.mWidth;
        mData.height = spec.mHeight;

        // if (!glfwInit())
        // {
        //     LOG_ERROR << "Failed to init GLFW";
        //     return;
        // }

        // // Setup context for Opengl 4.1 Core
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // mWindow = glfwCreateWindow(mData.width, mData.height, mData.title, nullptr, nullptr);
        // if (!mWindow) {
        //     LOG_ERROR << "Failed to create window";
        //     glfwTerminate();
        //     return;
        // }
        // LOG_INFO << "Window created successfully";
    }

    void window_glfw::shutdown()
    {

    }
}
