#include "Application.h"

#include "logger/Logger.h"
#include "platform/glfw/GLFWUtils.h"
#include "utils/Timestep.h"

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
            double time = Time::getTime();
            Timestep timestep = time - mLastFrameTime;
            mLastFrameTime = time;

            LOG_INFO << "FPS: " << 1 / timestep;

            mWindow->onUpdate();
        }
        onShutDown();
    }

    void Application::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);

        /* Window */
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(onWindowClosed));
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FUNCTION(onWindowResized));
        dispatcher.dispatch<WindowPosEvent>(BIND_EVENT_FUNCTION(onWindowPosChanged));

        /* Mouse */
        dispatcher.dispatch<MousePosEvent>(BIND_EVENT_FUNCTION(onMousePosChanged));
        dispatcher.dispatch<MouseEnterEvent>(BIND_EVENT_FUNCTION(onMouseEnterChanged));
        dispatcher.dispatch<MouseScrollEvent>(BIND_EVENT_FUNCTION(onMouseScrollChanged));
    }

    bool Application::onWindowClosed(WindowCloseEvent& e)
    {
        mRunning = false;
        return false;
    }

    bool Application::onWindowResized(WindowResizeEvent& e)
    {
        // LOG_INFO << "Window resized to " << e.getWidth() << "x" <<  e.getHeight();
        return false;
    }

    bool Application::onWindowPosChanged(WindowPosEvent& e)
    {
        // LOG_INFO << "Window Pos: " << e.getXPosition() << " " << e.getYPosition();
        return false;
    }

    bool Application::onMousePosChanged(MousePosEvent& e)
    {
        // LOG_INFO << "Window Pos: " << e.getXPosition() << " " << e.getYPosition();
        return false;
    }

    bool Application::onMouseEnterChanged(MouseEnterEvent& e)
    {
        // LOG_INFO << "Mouse enter: " << e.getEntered();
        return false;
    }

    bool Application::onMouseScrollChanged(MouseScrollEvent& e)
    {
        // LOG_INFO << "Mouse scroll: " << e.getXOffset() << ":" << e.getYOffset();
        return false;
    }
} // namespace core
