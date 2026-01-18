#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

namespace core
{
    class Renderer
    {
    public:
        virtual ~Renderer() = default;
        static void init();
        static void shutdown();
    };
} // core

#endif // CORE_RENDERER_H
