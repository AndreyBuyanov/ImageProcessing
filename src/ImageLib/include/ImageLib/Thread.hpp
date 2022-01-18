#pragma once

#include "ImageLib/IThread.hpp"

#include <memory>
#include <thread>

namespace ImageLib
{

class Thread:
    public IThread
{
public:
    explicit Thread(
        IRunnable *method);

    ~Thread() override;

    // IThread
    void Start() override;

    void Stop() override;

    [[nodiscard]] bool IsStopped() override;

private:
    IRunnable *m_Method;
    bool m_Stopped;
    std::unique_ptr<std::thread> m_ThreadObject;

    void Join();
};

}
