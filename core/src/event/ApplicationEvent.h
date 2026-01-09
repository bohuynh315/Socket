#ifndef CORE_APPLICATION_EVENT_H
#define CORE_APPLICATION_EVENT_H

#include "Event.h"

namespace core
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        virtual EventType getEventType() const override { return EventType::WindowClosedEvent; }
        virtual const char* getName() const override { return "WindowCloseEvent"; }
        static EventType getStaticType() { return EventType::WindowClosedEvent; }
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int width, int height)
            : mWidth(width), mHeight(height)
        {

        }

        int getWidth() const { return mWidth; }
        int getHeight() const { return mHeight; }

        virtual EventType getEventType() const override { return EventType::WindowResizedEvent; }
        virtual const char* getName() const override { return "WindowResizeEvent"; }
        static EventType getStaticType() { return EventType::WindowResizedEvent; }
    private:
        int mWidth, mHeight;
    };

    class WindowPosEvent : public Event
    {
    public:
        WindowPosEvent(int xpos, int ypos)
            : mXPos(xpos)
            , mYPos(ypos)
        {

        }

        int getXPosition() { return mXPos; }
        int getYPosition() { return mYPos; }

        virtual EventType getEventType() const override { return EventType::WindowPosEvent; }
        virtual const char* getName() const override { return "WindowPosEvent"; }
        static EventType getStaticType() { return EventType::WindowPosEvent; }

    private:
        int mXPos, mYPos;
    };
}

#endif // CORE_APPLICATION_EVENT_H
