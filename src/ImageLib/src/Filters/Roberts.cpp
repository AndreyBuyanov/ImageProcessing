#include "ImageLib/Filters/Roberts.hpp"
#include "ImageLib/ImageLib.hpp"
#include "ImageLib/BitmapView.hpp"
#include "ImageLib/Filters/FilterHelper.hpp"

#include <memory>
#include <cmath>

namespace ImageLib::Filters
{

const kernel2_t ROBERTS_H = {
     1.0f,  0.0f,
     0.0f, -1.0f
};

const kernel2_t ROBERTS_V = {
     0.0f,  1.0f,
    -1.0f,  0.0f
};

Roberts::Roberts() :
    m_Bitmap(nullptr),
    m_ProgressEventHandler(nullptr),
    m_FilterControlEventHandler(nullptr),
    m_Thread(CreateThread(this)) {}

void Roberts::ProcessBitmap()
{
    m_Thread->Start();
}

void Roberts::SetBitmap(
    IBitmap *bitmap)
{
    if (m_Thread->IsStopped()) {
        m_Bitmap = bitmap;
    }
}

void Roberts::RegisterProgressEventHandler(
    IProgressEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_ProgressEventHandler = handler;
    }
}

void Roberts::RegisterFilterControlEventHandler(
    IFilterControlEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_FilterControlEventHandler = handler;
    }
}

std::string Roberts::GetName() const
{
    return "Roberts";
}

void Roberts::Run()
{
    if (m_FilterControlEventHandler) {
        m_FilterControlEventHandler->FilterStarted();
    }

    if (m_Bitmap) {
        const auto w = m_Bitmap->Width();
        const auto h = m_Bitmap->Height();

        std::unique_ptr<IBitmap> hResult(FilterHelper::Grayscale(m_Bitmap, m_ProgressEventHandler));
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }
        FilterHelper::Convolution(hResult.get(), ROBERTS_H, m_ProgressEventHandler);
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }
        std::unique_ptr<IBitmap> vResult(FilterHelper::Grayscale(m_Bitmap, m_ProgressEventHandler));
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }
        FilterHelper::Convolution(vResult.get(), ROBERTS_V, m_ProgressEventHandler);
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }

        BitmapView srcHview { hResult.get() };
        BitmapView srcVview { vResult.get() };
        BitmapView dstView { m_Bitmap };

        for (std::uint32_t y = 0; y < h; y++) {
            for (std::uint32_t x = 0; x < w; x++) {
                const auto value = static_cast<std::uint8_t>(
                    clamp(std::hypot(
                        static_cast<float>(srcHview.GetPixel(x, y, 0)),
                        static_cast<float>(srcVview.GetPixel(x, y, 0))),
                        F_MIN, F_MAX));
                dstView.SetPixel(x, y, 0, value);
                dstView.SetPixel(x, y, 1, value);
                dstView.SetPixel(x, y, 2, value);
            }
            if (m_ProgressEventHandler) {
                m_ProgressEventHandler->UpdateProgress(std::int32_t(float(y) / h * 100));
            }
        }
    }

    if (m_FilterControlEventHandler) {
        m_FilterControlEventHandler->FilterFinished();
    }
}

}
