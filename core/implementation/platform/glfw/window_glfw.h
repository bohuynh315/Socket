#ifndef CORE_WINDOW_GLFW_H
#define CORE_WINDOW_GLFW_H

#include "window.h"
#include "GLFW/glfw3.h"

namespace core
{
    class window_glfw : public window
    {
    public:
        explicit window_glfw(const window_spec& spec);
        virtual ~window_glfw();

        void* get_native_window() { return mWindow; }

    private:
        void init(const window_spec& spec);
        void shutdown();

    private:
        GLFWwindow* mWindow;

        typedef struct window_data
        {
            const char* title;
            int width, height;
            // Callback
        } window_data_t;
        window_data_t mData;        
    };
}

#endif // CORE_WINDOW_GLFW_H
