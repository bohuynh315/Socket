#ifndef CORE_WINDOW_GLFW_H
#define CORE_WINDOW_GLFW_H

#include "window.h"
#include "GLFW/glfw3.h"
#include "renderer/graphic_context.h"

namespace core
{
    class GLFWWindow : public Window
    {
    public:
        explicit GLFWWindow(const WindowSpecs& spec);
        virtual ~GLFWWindow();

        virtual void onUpdate() override;
        virtual void* getNativeWindow() override { return mWindow; }
        virtual void setEventCallback(const EventCallback& callback) override { mData.event_callback = callback; }

    private:
        void init(const WindowSpecs& spec);
        void shutdown();

    private:
        GLFWwindow* mWindow;
        Scope<GraphicContext> mContext;

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
