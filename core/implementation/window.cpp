#include "window.h"
#include "platform/glfw/glfw_window.h"

namespace core
{
    Scope<Window> Window::create(const WindowSpecs& spec)
    {
        return CreateScope<GLFWWindow>(spec);
    }
}
