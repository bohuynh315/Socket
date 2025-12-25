#include "graphic_context.h"
#include "platform/opengl/opengl_context.h"

namespace core
{
    Scope<graphic_context> graphic_context::create(void* native_window)
    {
        return CreateScope<opengl_context>(static_cast<GLFWwindow*>(native_window));
    }
} // namespace core
