#ifndef CORE_ENTRY_H
#define CORE_ENTRY_H

#include "application.h"

int main(int argc, char** argv)
{
    core::Application* app = core::create();
    app->run();

    FREE_MEMORY(app);
    return 0;
};

#endif // CORE_ENTRY_H
