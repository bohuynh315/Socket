#include "window_glfw.h"

#include "logger.h"

#include "event/application_event.h"

namespace core
{
    GLFWWindow::GLFWWindow(const WindowSpecs &spec)
        : mWindow(nullptr)
    {
        init(spec);
    }

    GLFWWindow::~GLFWWindow()
    {
        shutdown();
    }

    void GLFWWindow::init(const WindowSpecs &spec)
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

        mContext = GraphicContext::create(mWindow);
        mContext->init();

        glfwSetWindowUserPointer(mWindow, &mData);

        glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
            WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            data->event_callback(event);
        });

        glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
            WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);
            data->width = width;
            data->height = height;

            WindowResizeEvent event(width, height);
            data->event_callback(event);
        });

        glfwSetWindowPosCallback(mWindow, [](GLFWwindow* window, int xpos, int ypos) {
            WindowData *data = (WindowData*)glfwGetWindowUserPointer(window);

            WindowPosEvent event(xpos, ypos);
            data->event_callback(event);
        });
    }

    void GLFWWindow::shutdown()
    {
        glfwTerminate();
    }

    void GLFWWindow::onUpdate()
    {
        mContext->swap_buffers();
        glfwPollEvents();
    }
}
