#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#include "Window.h"
#include "Base.h"

#include "event/ApplicationEvent.h"
#include "event/MouseEvent.h"
#include "LayerStack.h"

namespace core
{
    typedef struct
    {
        int width;
        int height;
        const char* title;
        float fps;
    } app_spec_t;

    class Application
    {
    public:
        virtual ~Application() = default;

        virtual void onInit() = 0;
        virtual void onShutDown() = 0;
        static Application& get() { return *sInstance; }

        void run();

        void pushOverlay(Layer* layer);
        void pushLayer(Layer* layer);

    public:
        Application() = default;
        Application(const app_spec_t &);

    private:
        void onEvent(Event& e);
        bool onWindowClosed(WindowCloseEvent& e);
        bool onWindowResized(WindowResizeEvent& e);
        bool onWindowPosChanged(WindowPosEvent& e);
        bool onMousePosChanged(MousePosEvent& e);
        bool onMouseEnterChanged(MouseEnterEvent& e);
        bool onMouseScrollChanged(MouseScrollEvent& e);

    private:
        app_spec_t mSpec;
        bool mRunning;
        Scope<Window> mWindow;
        LayerStack mLayerStack;
        double mLastFrameTime = 0.0f;

    private:
        static Application *sInstance;
    };

    extern Application* create();
}

#endif // CORE_APPLICATION_H
