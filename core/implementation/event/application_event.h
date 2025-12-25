#ifndef CORE_APPLICATION_EVENT_H
#define CORE_APPLICATION_EVENT_H

#include "event.h"

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
}

#endif // CORE_APPLICATION_EVENT_H
