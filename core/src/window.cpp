#include "Window.h"
#include "platform/glfw/GLFWWindow.h"

namespace core
{
    Scope<Window> Window::create(const WindowSpecs& spec)
    {
        return CreateScope<GLFWWindow>(spec);
    }
}
