#pragma once

#include "ImageLib/Filters/IMedian.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib::Filters
{

class Median3 :
    public IMedian3,
    public IRunnable
{
public:
    Median3();
    ~Median3() override = default;

    // IInvert
    void ProcessBitmap() override;

    void SetBitmap(
        IBitmap *bitmap) override;

    void RegisterProgressEventHandler(
        IProgressEventHandler *handler) override;
    void RegisterFilterControlEventHandler(
        IFilterControlEventHandler *handler) override;

    [[nodiscard]] std::string GetName() const override;

    // IRunnable
    void Run() override;

private:
    IBitmap *m_Bitmap;
    IProgressEventHandler *m_ProgressEventHandler;
    IFilterControlEventHandler *m_FilterControlEventHandler;
    IThread *m_Thread;
};

}
