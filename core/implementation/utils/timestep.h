#ifndef CORE_TIMESTEP_H
#define CORE_TIMESTEP_H

namespace core
{
    class Timestep
    {
    public:
        Timestep(float time = 0.0f)
            : mTime(time)
        {

        }

        operator float() const { return mTime; }

        float GetSeconds() const { return mTime; }
        float GetMilliSeconds() const { return mTime * 1000.0f; }

    private:
        float mTime;
    };
} // namespace core

#endif // CORE_TIMESTEP_H