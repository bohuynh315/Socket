#ifndef CORE_WINDOW_GLFW_H
#define CORE_WINDOW_GLFW_H

#include "window.h"
#include "GLFW/glfw3.h"

namespace core
{
    class window_glfw : public window
    {
    public:
        explicit window_glfw();
        virtual ~window_glfw();

        void* get_native_window() { return mWindow; }

    private:
        GLFWwindow* mWindow;
    };
}

#endif // CORE_WINDOW_GLFW_H
