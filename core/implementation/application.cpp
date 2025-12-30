#include "application.h"

#include "logger.h"

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
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FUNCTION(onWindowResized));
        dispatcher.dispatch<WindowPosEvent>(BIND_EVENT_FUNCTION(onWindowPosChanged));
    }

    bool Application::onWindowClosed(WindowCloseEvent& e)
    {
        mRunning = false;
        return false;
    }

    bool Application::onWindowResized(WindowResizeEvent& e)
    {
        LOG_INFO << "Window resized to " << e.getWidth() << "x" <<  e.getHeight();
        return false;
    }

    bool Application::onWindowPosChanged(WindowPosEvent& e)
    {
        LOG_INFO << "Window Pos: " << e.getXPosition() << " " << e.getYPosition();
        return false;
    }
}
