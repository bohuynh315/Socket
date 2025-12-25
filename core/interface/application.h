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

    class application
    {
    public:
        virtual ~application() = default;

        virtual void onInit() = 0;
        virtual void onShutDown() = 0;
        static application& get() { return *sInstance; }

        void run();

    public:
        application() = default;
        application(const app_spec_t &);

    private:
        void onEvent(event& e);
        bool onWindowClosed(window_close_event& e);

    private:
        app_spec_t mSpec;
        bool mRunning;
        Scope<window> mWindow;

    private:
        static application *sInstance;
    };

    extern application* create();
}

#endif // CORE_APPLICATION_H
