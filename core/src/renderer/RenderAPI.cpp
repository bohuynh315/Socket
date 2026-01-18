#include "RenderAPI.h"

#include "platform/opengl/OpenGLRenderAPI.h"

namespace core
{
    Scope<RenderAPI> RenderAPI::create()
    {
        return CreateScope<OpenGLRenderAPI>();
    }
}
