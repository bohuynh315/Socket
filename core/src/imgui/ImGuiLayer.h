#ifndef CORE_IMGUI_LAYER_H
#define CORE_IMGUI_LAYER_H

#include "Layer.h"

namespace core
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer(const std::string &name);
        ~ImGuiLayer();

        virtual void onAttach();
        virtual void onDetach();
        virtual void onUpdate(Timestep ts);

        virtual void onEvent(Event &event);
    };
}

#endif // CORE_IMGUI_LAYER_H
