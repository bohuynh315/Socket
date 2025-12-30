#include "entry.h"
#include "logger.h"
#include "socket/client.h"

#define APP_WIDTH 380
#define APP_HEIGHT 600
#define APP_TITLE "Client"

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8080

class ClientApplication : public core::Application
{
public:
    ClientApplication(const core::app_spec_t &spec)
        : core::Application(spec)
    {

    }

    virtual ~ClientApplication()
    {

    }

    virtual void onInit() override
    {
        LOG_INFO << "Client is initialized\n";

        mClient = core::Client::create(SERVER_ADDRESS, SERVER_PORT);
        if (mClient == nullptr)
        {
            LOG_ERROR << "Failed to create client\n";
            return;
        }

        if (mClient->start() != E_OK)
        {
            LOG_ERROR << "Failed to start client\n";
            return;
        }
    }

    virtual void onShutDown() override
    {
        LOG_INFO << "Client is shutting down\n";
        if (mClient != nullptr)
        {
            mClient->stop();
        }
    }

private:
    core::Scope<core::Client> mClient;
};

core::Application *core::create()
{
    core::app_spec_t specs;
    specs.width = APP_WIDTH;
    specs.height = APP_HEIGHT;
    specs.title = APP_TITLE;

    return new ClientApplication(specs);
}
