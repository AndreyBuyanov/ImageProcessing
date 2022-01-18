#pragma once

#include "ImageLib/Filters/ICanny.hpp"
#include "ImageLib/IThread.hpp"

namespace ImageLib::Filters
{

class Canny :
    public ICanny,
    public IRunnable
{
public:
    Canny();
    ~Canny() override = default;

    // IFilter
    void ProcessBitmap() override;

    void SetBitmap(
        IBitmap *bitmap) override;

    void RegisterProgressEventHandler(
        IProgressEventHandler *handler) override;
    void RegisterFilterControlEventHandler(
        IFilterControlEventHandler *handler) override;

    [[nodiscard]] std::string GetName() const override;

    // ICanny
    void SetSigma(
        float sigma) override;

    void SetLowThreshold(
        std::uint8_t lowThreshold) override;

    void SetHighThreshold(
        std::uint8_t highThreshold) override;

    // IRunnable
    void Run() override;

private:
    IBitmap *m_Bitmap;
    IProgressEventHandler *m_ProgressEventHandler;
    IFilterControlEventHandler *m_FilterControlEventHandler;
    IThread *m_Thread;
    float m_Sigma;
    std::uint8_t m_LowThreshold;
    std::uint8_t m_HighThreshold;
};

}
