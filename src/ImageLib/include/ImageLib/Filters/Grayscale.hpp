#pragma once

#include "ImageLib/Filters/IGrayscale.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib::Filters
{

class Grayscale :
    public IGrayscale,
    public IRunnable
{
public:
    Grayscale();
    ~Grayscale() override = default;

    // IGrayscale
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
