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
    }

    void application::run()
    {
        on_init();
        while (mRunning)
        {
            mWindow->on_update();
        }
        on_shutdown();
    }
}
