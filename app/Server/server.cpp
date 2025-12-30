#include "entry.h"
#include "logger.h"
#include "socket/server.h"

#include <thread>

#define APP_WIDTH       380
#define APP_HEIGHT      600
#define APP_TITLE       "Server"

#define SERVER_ADDRESS  "127.0.0.1"
#define SERVER_PORT     8080

class ServerApplication : public core::Application
{
public:
    ServerApplication(const core::app_spec_t &spec)
        : core::Application(spec)
    {

    }

    virtual ~ServerApplication()
    {

    }

    virtual void onInit() override
    {
        LOG_INFO << "Server is initialized";

        mServer = core::Server::create(SERVER_ADDRESS, SERVER_PORT);
        if (!mServer)
        {
            LOG_ERROR << "Failed to create server";
            return;
        }

        socket_error_t ret = mServer->start();
        if (ret != E_OK)
        {
            LOG_ERROR << "Failed to start server";
            return;
        }
    }

    virtual void onShutDown() override
    {
        LOG_INFO << "Server is shutting down";
        if (mServer)
        {
            mServer->stop();
        }
    }

private:
    core::Scope<core::Server> mServer;
};

core::Application *core::create()
{
    core::app_spec_t specs;
    specs.width = APP_WIDTH;
    specs.height = APP_HEIGHT;
    specs.title = APP_TITLE;

    return new ServerApplication(specs);
}
