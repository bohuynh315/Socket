#ifndef CORE_RENDER_API_H
#define CORE_RENDER_API_H

#include "Base.h"

namespace core
{
    class RenderAPI
    {
    public:
        virtual ~RenderAPI() = default;

        virtual void init() = 0;

        virtual void setViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        virtual void clear() = 0;

        static Scope<RenderAPI> create();
    };
}

#endif // CORE_RENDER_API_H
