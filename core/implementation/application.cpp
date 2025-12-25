#include "application.h"

namespace core
{
    application *application::sInstance = nullptr;

    application::application(const app_spec_t &spec)
        : mSpec(spec), mRunning(true)
    {
        sInstance = this;

        window_spec win_spec;
        win_spec.mTitle = spec.title;
        win_spec.mWidth = spec.width;
        win_spec.mHeight = spec.height;
        mWindow = window::create(win_spec);
        mWindow->set_event_callback(BIND_EVENT_FUNCTION(onEvent));
    }

    void application::run()
    {
        onInit();
        while (mRunning)
        {
            mWindow->onUpdate();
        }
        onShutDown();
    }

    void application::onEvent(event& e)
    {
        event_dispatcher dispatcher(e);
        dispatcher.dispatch<window_close_event>(BIND_EVENT_FUNCTION(onWindowClosed));
    }

    bool application::onWindowClosed(window_close_event& e)
    {
        mRunning = false;
        return false;
    }
}
