#ifndef CORE_OPENGL_CONTEXT_H
#define CORE_OPENGL_CONTEXT_H

#include "renderer/graphic_context.h"
#include <GLFW/glfw3.h>

namespace core
{
    class OpenGLContext : public GraphicContext
    {
    public:
        OpenGLContext(GLFWwindow* window);
        virtual ~OpenGLContext() = default;

        virtual void init() override;
        virtual void swap_buffers() override;
    
    private:
        GLFWwindow* mWindow;
    };
}

#endif // CORE_OPENGL_CONTEXT_H
