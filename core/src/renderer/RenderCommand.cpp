#include "RenderCommand.h"

namespace core
{
    Scope<RenderAPI> RenderCommand::mRenderAPI = RenderAPI::create();

    void RenderCommand::init()
    {
        mRenderAPI->init();
    }

    void RenderCommand::setViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        mRenderAPI->setViewPort(x, y, width, height);
    }

    void RenderCommand::clear()
    {
        mRenderAPI->clear();
    }
} // namespace core
