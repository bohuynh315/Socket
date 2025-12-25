#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "define.h"
#include "event.h"

namespace core
{
    class window_spec
    {
    public:
        window_spec(const std::string& title = "window",
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
    
    class window
    {
    public:
        using EventCallback = std::function<void(event&)>;

        virtual ~window() = default;
        virtual void onUpdate() = 0;

        virtual void* get_native_window() = 0;
        virtual void set_event_callback(const EventCallback& callback) = 0;

        static Scope<window> create(const window_spec& spec = window_spec());
    };
}

#endif // CORE_WINDOW_H
