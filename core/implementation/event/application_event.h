#ifndef CORE_APPLICATION_EVENT_H
#define CORE_APPLICATION_EVENT_H

#include "event.h"

namespace core
{
    class window_close_event : public event
    {
    public:
        window_close_event() = default;

        virtual event_type_t get_event_type() const override { return event_type_t::WindowClosedEvent; }
        virtual const char* get_name() const override { return "WindowCloseEvent"; }
        static event_type_t get_static_type() { return event_type_t::WindowClosedEvent; }
    };
}

#endif // CORE_APPLICATION_EVENT_H
