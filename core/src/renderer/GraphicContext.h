#ifndef CORE_GRAPHIC_CONTEXT_H
#define CORE_GRAPHIC_CONTEXT_H

#include "Base.h"

namespace core
{
    class GraphicContext
    {
    public:
        virtual ~GraphicContext() = default;

        virtual void init() = 0;
        virtual void swapBuffers() = 0;

        static Scope<GraphicContext> create(void* native_window);
    };
}

#endif // CORE_GRAPHIC_CONTEXT_H
