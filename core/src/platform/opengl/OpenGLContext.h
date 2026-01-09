#ifndef CORE_OPENGL_CONTEXT_H
#define CORE_OPENGL_CONTEXT_H

#include "renderer/GraphicContext.h"

class GLFWwindow;

namespace core
{
    class OpenGLContext : public GraphicContext
    {
    public:
        OpenGLContext(GLFWwindow* window);
        virtual ~OpenGLContext() = default;

        virtual void init() override;
        virtual void swapBuffers() override;

    private:
        GLFWwindow* mWindow;
    };
}

#endif // CORE_OPENGL_CONTEXT_H
