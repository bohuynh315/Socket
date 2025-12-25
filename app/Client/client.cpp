#include "entry.h"
#include "logger.h"
#include "socket/client.h"

#define SERVER_ADDRESS  "127.0.0.1"
#define SERVER_PORT     8080

class ClientApplication : public core::Application
{
public:
    ClientApplication(const core::app_spec_t& spec)
        : core::Application(spec)
    {

    }

    virtual ~ClientApplication()
    {

    }

    virtual void onInit() override
    {
        LOG_INFO << "Client is initialized\n";

        core::Scope<core::client> socket = core::client::create(SERVER_ADDRESS, SERVER_PORT);
        if (!socket)
        {
            LOG_ERROR << "Failed to create client\n";
            return;
        }

        if (socket->start() != E_OK)
        {
            LOG_ERROR << "Failed to start client\n";
            return;
        }   
    }

    virtual void onShutDown() override
    {
        LOG_INFO << "Client is shutting down\n";

    }
};

core::Application* core::create()
{
    core::app_spec_t specs;
    specs.width = 800;
    specs.height = 600;
    specs.title = "Client";

    return new ClientApplication(specs);
}
