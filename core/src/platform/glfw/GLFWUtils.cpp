#include "GLFWUtils.h"

#include "GLFW/glfw3.h"

namespace core
{
    double Time::getTime() {
        return glfwGetTime();
    }
}
