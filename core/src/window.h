#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "Define.h"
#include "Event.h"

namespace core
{
    class WindowSpecs
    {
    public:
        WindowSpecs(const std::string& title = "window",
                    const uint32_t width = 480,
                    const uint32_t height = 600)
            : mTitle(title)
            , mWidth(width)
            , mHeight(height)
        {

        }

        std::string mTitle;
        uint32_t mWidth;
        uint32_t mHeight;
    };
    
    class Window
    {
    public:
        using EventCallback = std::function<void(Event&)>;

        virtual ~Window() = default;
        virtual void onUpdate() = 0;

        virtual void* getNativeWindow() = 0;
        virtual void setEventCallback(const EventCallback& callback) = 0;

        static Scope<Window> create(const WindowSpecs& spec = WindowSpecs());
    };
}

#endif // CORE_WINDOW_H
