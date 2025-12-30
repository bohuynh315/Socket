#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#include "window.h"

#include "event/application_event.h"

namespace core
{
    typedef struct
    {
        int width;
        int height;
        const char* title;
    } app_spec_t;

    class Application
    {
    public:
        virtual ~Application() = default;

        virtual void onInit() = 0;
        virtual void onShutDown() = 0;
        static Application& get() { return *sInstance; }

        void run();

    public:
        Application() = default;
        Application(const app_spec_t &);

    private:
        void onEvent(Event& e);
        bool onWindowClosed(WindowCloseEvent& e);
        bool onWindowResized(WindowResizeEvent& e);
        bool onWindowPosChanged(WindowPosEvent& e);

    private:
        app_spec_t mSpec;
        bool mRunning;
        Scope<Window> mWindow;

    private:
        static Application *sInstance;
    };

    extern Application* create();
}

#endif // CORE_APPLICATION_H
