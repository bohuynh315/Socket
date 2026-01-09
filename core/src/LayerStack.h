#ifndef CORE_LAYERSTACK_H
#define CORE_LAYERSTACK_H

#include <vector>
#include "Layer.h"

namespace core
{
    class LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack();

        void pushLayer(Layer *layer);
        void pushOverlay(Layer *overlay);
        void popLayer(Layer *layer);
        void popOverlay(Layer *overlay);

        std::vector<Layer *>::iterator begin() { return mLayers.begin(); }
        std::vector<Layer *>::iterator end() { return mLayers.end(); }
        std::vector<Layer *>::reverse_iterator rbegin() { return mLayers.rbegin(); }
        std::vector<Layer *>::reverse_iterator rend() { return mLayers.rend(); }

    private:
        std::vector<Layer *> mLayers;
        uint8_t mLayerInsertIndex = 0;
    };
}

#endif // CORE_LAYERSTACK_H