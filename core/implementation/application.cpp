#include "application.h"

namespace core
{
    Application *Application::sInstance = nullptr;

    Application::Application(const app_spec_t &spec)
        : mSpec(spec)
        , mRunning(true)
    {
        sInstance = this;

        WindowSpecs win_spec;
        win_spec.mTitle = spec.title;
        win_spec.mWidth = spec.width;
        win_spec.mHeight = spec.height;
        mWindow = Window::create(win_spec);
        mWindow->setEventCallback(BIND_EVENT_FUNCTION(onEvent));
    }

    void Application::run()
    {
        onInit();
        while (mRunning)
        {
            mWindow->onUpdate();
        }
        onShutDown();
    }

    void Application::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(onWindowClosed));
    }

    bool Application::onWindowClosed(WindowCloseEvent& e)
    {
        mRunning = false;
        return false;
    }
}
