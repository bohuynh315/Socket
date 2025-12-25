#include "opengl_context.h"

#include "logger.h"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

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

    void OpenGLContext::swap_buffers()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(mWindow);
    }
} // namespace core
