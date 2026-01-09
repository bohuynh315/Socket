#include "GraphicContext.h"
#include "platform/opengl/OpenGLContext.h"

namespace core
{
    Scope<GraphicContext> GraphicContext::create(void* native_window)
    {
        return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(native_window));
    }
} // namespace core
