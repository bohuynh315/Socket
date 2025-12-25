#ifndef CORE_GRAPHIC_CONTEXT_H
#define CORE_GRAPHIC_CONTEXT_H

#include "define.h"

namespace core
{
    class graphic_context
    {
    public:
        virtual ~graphic_context() = default;

        virtual void init() = 0;
        virtual void swap_buffers() = 0;

        static Scope<graphic_context> create(void* native_window);
    };
}

#endif // CORE_GRAPHIC_CONTEXT_H
