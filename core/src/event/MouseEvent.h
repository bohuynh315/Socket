#ifndef CORE_MOUSE_EVENT_H
#define CORE_MOUSE_EVENT_H

#include "Event.h"

namespace core
{
    class MousePosEvent : public Event
    {
    public:
        MousePosEvent(double xpos, double ypos)
            : mXPos(xpos)
            , mYPos(ypos)
        {

        }

        double getXPosition() { return mXPos; }
        double getYPosition() { return mYPos; }

        virtual EventType getEventType() const override { return EventType::MousePosEvent; }
        virtual const char *getName() const override { return "MousePosEvent"; }
        static EventType getStaticType() { return EventType::MousePosEvent; }

    private:
        double mXPos, mYPos;
    };

    class MouseEnterEvent : public Event
    {
    public:
        MouseEnterEvent(int entered)
            : mEntered(entered)
        {

        }

        int getEntered() { return mEntered; }

        virtual EventType getEventType() const override { return EventType::MouseEnterEvent; }
        virtual const char *getName() const override { return "MouseEnterEvent"; }
        static EventType getStaticType() { return EventType::MouseEnterEvent; }
    
    private:
        int mEntered;
    };

    class MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(double xoffset, double yoffset)
            : mXOffset(xoffset)
            , mYOffset(yoffset)
        {

        }

        double getXOffset() { return mXOffset; }
        double getYOffset() { return mYOffset; }

        virtual EventType getEventType() const override { return EventType::MouseScrollEvent; }
        virtual const char *getName() const override { return "MouseScrollEvent"; }
        static EventType getStaticType() { return EventType::MouseScrollEvent; }

    private:
        double mXOffset, mYOffset;
    };
}

#endif // CORE_MOUSE_EVENT_H