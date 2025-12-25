#ifndef CORE_EVENT_H
#define CORE_EVENT_H

namespace core
{
    enum class event_type_t
    {
        None = 0,
        WindowClosedEvent, WindowResizedEvent,
        MousePosEvent, MousePressEvent, MouseReleaseButtonEvent, MouseScrolledEvent,
        KeyPressedEvent, KeyReleasedEvent
    };

    class event
    {
    public:
        virtual ~event() = default;

        bool handled = false;

        virtual event_type_t get_event_type() const = 0;
        virtual const char* get_name() const = 0;
    };

    class event_dispatcher
    {
    public:
        event_dispatcher(event &event)
            : mEvent(event)
        {

        }

        template<typename T, typename F>
		bool dispatch(const F& func)
		{
            // CORE_LOGD("Run time type : {0} and expected type : {1}", static_cast<int>(mEvent.GetEventType()), static_cast<int>(T::GetStaticType()));
			if (mEvent.get_event_type() == T::get_static_type())
			{
				mEvent.handled |= func(static_cast<T&>(mEvent));
				return true;
			}
			return false;
		}

    private:
        event& mEvent;
    };
}

#endif // CORE_EVENT_H
