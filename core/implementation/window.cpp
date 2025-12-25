#include "window.h"
#include "platform/glfw/window_glfw.h"

namespace core
{
    Scope<Window> Window::create(const WindowSpecs& spec)
    {
        return CreateScope<GLFWWindow>(spec);
    }
}
