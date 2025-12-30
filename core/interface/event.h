#ifndef CORE_EVENT_H
#define CORE_EVENT_H

namespace core
{
    enum class EventType
    {
        None = 0,
        WindowClosedEvent, WindowResizedEvent, WindowPosEvent,
        MousePosEvent, MouseEnterEvent, MousePressEvent, MouseReleaseButtonEvent, MouseScrolledEvent,
        KeyPressedEvent, KeyReleasedEvent
    };

    class Event
    {
    public:
        virtual ~Event() = default;

        bool handled = false;

        virtual EventType getEventType() const = 0;
        virtual const char* getName() const = 0;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event &event)
            : mEvent(event)
        {

        }

        template<typename T, typename F>
		bool dispatch(const F& func)
		{
            // ("Run time type : {0} and expected type : {1}", static_cast<int>(mEvent.GetEventType()), static_cast<int>(T::GetStaticType()));
			if (mEvent.getEventType() == T::getStaticType())
			{
				mEvent.handled |= func(static_cast<T&>(mEvent));
				return true;
			}
			return false;
		}

    private:
        Event& mEvent;
    };
}

#endif // CORE_EVENT_H
