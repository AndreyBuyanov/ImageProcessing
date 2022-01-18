#pragma once

#include "ImageLib/Filters/IGamma.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib::Filters
{

class Gamma :
    public IGamma,
    public IRunnable
{
public:
    Gamma();
    ~Gamma() override = default;

    // IFilter
    void ProcessBitmap() override;

    void SetBitmap(
        IBitmap *bitmap) override;

    void RegisterProgressEventHandler(
        IProgressEventHandler *handler) override;
    void RegisterFilterControlEventHandler(
        IFilterControlEventHandler *handler) override;

    [[nodiscard]] std::string GetName() const override;

    // IGamma
    void SetGamma(
        float gamma) override;

    // IRunnable
    void Run() override;

private:
    IBitmap *m_Bitmap;
    IProgressEventHandler *m_ProgressEventHandler;
    IFilterControlEventHandler *m_FilterControlEventHandler;
    IThread *m_Thread;
    float m_Gamma;
};

}
