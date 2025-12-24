#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

namespace core
{
    typedef struct
    {
        int width;
        int height;
        const char* title;
    } app_spec_t;
    
    class application
    {
    public:
        virtual ~application() = default;

    private:
        application() = default;
        application(const app_spec_t&);
    
    private:
        
    };
}

#endif // CORE_APPLICATION_H
