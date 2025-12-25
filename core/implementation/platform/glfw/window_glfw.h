#ifndef CORE_WINDOW_GLFW_H
#define CORE_WINDOW_GLFW_H

#include "window.h"
#include "GLFW/glfw3.h"
#include "renderer/graphic_context.h"

namespace core
{
    class window_glfw : public window
    {
    public:
        explicit window_glfw(const window_spec& spec);
        virtual ~window_glfw();

        virtual void onUpdate() override;
        virtual void* get_native_window() override { return mWindow; }
        virtual void set_event_callback(const EventCallback& callback) override { mData.event_callback = callback; }

    private:
        void init(const window_spec& spec);
        void shutdown();

    private:
        GLFWwindow* mWindow;
        Scope<graphic_context> mContext;

        typedef struct window_data
        {
            const char* title;
            int width, height;
            EventCallback event_callback;
        } window_data_t;
        window_data_t mData;
    };
}

#endif // CORE_WINDOW_GLFW_H
