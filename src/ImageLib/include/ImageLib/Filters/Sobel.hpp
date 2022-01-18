#pragma once

#include "ImageLib/Filters/ISobel.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib::Filters
{

class Sobel :
    public ISobel,
    public IRunnable
{
public:
    Sobel();
    ~Sobel() override = default;

    // ISobel
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
