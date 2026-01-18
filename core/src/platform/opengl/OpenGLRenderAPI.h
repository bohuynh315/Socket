#ifndef CORE_OPENGL_RENDER_API_H
#define CORE_OPENGL_RENDER_API_H

#include "renderer/RenderAPI.h"

namespace core
{
    class OpenGLRenderAPI : public RenderAPI
    {
    public:
        OpenGLRenderAPI();
        ~OpenGLRenderAPI();

        virtual void init() override;
        virtual void setViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        virtual void clear() override;
    };
} // core


#endif // CORE_OPENGL_RENDER_API_H