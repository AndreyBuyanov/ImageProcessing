#pragma once

namespace ImageLib
{

class IRunnable
{
public:
    virtual ~IRunnable() = default;

    virtual void Run() = 0;
};

class IThread
{
public:
    virtual ~IThread() = default;

    virtual void Start() = 0;

    virtual void Stop() = 0;

    virtual bool IsStopped() = 0;
};

}