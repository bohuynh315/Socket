#include "OpenGLContext.h"

#include "logger/Logger.h"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace core
{
    OpenGLContext::OpenGLContext(GLFWwindow *window)
        : mWindow(window)
    {

    }

    void OpenGLContext::init()
    {
        glfwMakeContextCurrent(mWindow);
        int statue = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
        if (!statue)
        {
            LOG_ERROR << "Failed to initialize Glad";
        }
    }

    void OpenGLContext::swapBuffers()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(mWindow);
    }
} // namespace core
