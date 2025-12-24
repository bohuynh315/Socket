#include "window.h"
#include "platform/glfw/window_glfw.h"

namespace core
{
    Scope<window> window::create(const window_spec& spec)
    {
        return CreateScope<window_glfw>();
    }
}
