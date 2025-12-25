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
        shutdown();
    }

    void window_glfw::init(const window_spec &spec)
    {
        mData.title = spec.mTitle.c_str();
        mData.width = spec.mWidth;
        mData.height = spec.mHeight;

        if (!glfwInit())
        {
            LOG_ERROR << "Failed to init GLFW";
            return;
        }

        // Setup context for Opengl 4.1 Core
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        mWindow = glfwCreateWindow(mData.width, mData.height, mData.title, nullptr, nullptr);
        if (mWindow == nullptr)
        {
            LOG_ERROR << "Failed to create window";
            glfwTerminate();
            return;
        }
        LOG_INFO << "Window created successfully";

        mContext = graphic_context::create(mWindow);
        mContext->init();
    }

    void window_glfw::shutdown()
    {
        glfwTerminate();
    }

    void window_glfw::on_update()
    {
        mContext->swap_buffers();
        glfwPollEvents();
    }
}
