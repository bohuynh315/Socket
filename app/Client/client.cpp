#include "entry.h"
#include "logger.h"
#include "socket/client.h"

#define SERVER_ADDRESS  "127.0.0.1"
#define SERVER_PORT     8080

class client_application : public core::application
{
public:
    client_application(const core::app_spec_t& spec)
        : core::application(spec)
    {

    }

    virtual ~client_application()
    {

    }

    virtual void on_init() override
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

    virtual void on_shutdown() override
    {
        LOG_INFO << "Client is shutting down\n";

    }
};

core::application* core::create()
{
    core::app_spec_t specs;
    specs.width = 800;
    specs.height = 600;
    specs.title = "Client";

    return new client_application(specs);
}
