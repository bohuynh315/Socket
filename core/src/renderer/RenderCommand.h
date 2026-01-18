#ifndef CORE_RENDER_COMMAND_H
#define CORE_RENDER_COMMAND_H

#include "RenderAPI.h"

namespace core
{
    class RenderCommand
    {
    public:
        static void init();
        static void setViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
        static void clear();

    private:
        static Scope<RenderAPI> mRenderAPI;
    };
}

#endif // CORE_RENDER_COMMAND_H
