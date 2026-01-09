#ifndef CORE_LAYER_H
#define CORE_LAYER_H

#include <string>

#include "utils/Timestep.h"
#include "event/Event.h"

namespace core
{

    class Layer
    {
    public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer() = default;

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate(Timestep ts) {}
        virtual void onImGuiRender() {}
        virtual void onEvent(Event &event) {}

        const std::string &GetName() const { return mDebugName; }

    protected:
        std::string mDebugName;
    };
}

#endif // CORE_LAYER_H