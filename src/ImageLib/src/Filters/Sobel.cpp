#include "ImageLib/Filters/Sobel.hpp"
#include "ImageLib/ImageLib.hpp"
#include "ImageLib/BitmapHelper.hpp"
#include "ImageLib/Filters/FilterHelper.hpp"

#include <memory>
#include <cmath>

namespace ImageLib::Filters
{

const kernel_t SOBEL_H = {
    -1.0f,  0.0f,  1.0f,
    -2.0f,  0.0f,  2.0f,
    -1.0f,  0.0f,  1.0f,
};

const kernel_t SOBEL_V = {
     1.0f,  2.0f,  1.0f,
     0.0f,  0.0f,  0.0f,
    -1.0f, -2.0f, -1.0f,
};

Sobel::Sobel() :
    m_Bitmap(nullptr),
    m_ProgressEventHandler(nullptr),
    m_FilterControlEventHandler(nullptr),
    m_Thread(CreateThread(this)) {}

void Sobel::ProcessBitmap()
{
    m_Thread->Start();
}

void Sobel::SetBitmap(
    IBitmap *bitmap)
{
    if (m_Thread->IsStopped()) {
        m_Bitmap = bitmap;
    }
}

void Sobel::RegisterProgressEventHandler(
    IProgressEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_ProgressEventHandler = handler;
    }
}

void Sobel::RegisterFilterControlEventHandler(
    IFilterControlEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_FilterControlEventHandler = handler;
    }
}

std::string Sobel::GetName() const
{
    return "Sobel";
}

void Sobel::Run()
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
        FilterHelper::Convolution(hResult.get(), SOBEL_H, m_ProgressEventHandler);
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }
        std::unique_ptr<IBitmap> vResult(FilterHelper::Grayscale(m_Bitmap, m_ProgressEventHandler));
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }
        FilterHelper::Convolution(vResult.get(), SOBEL_V, m_ProgressEventHandler);
        if (m_ProgressEventHandler) {
            m_ProgressEventHandler->UpdateProgress(0);
        }

        auto* dst = m_Bitmap->Data();
        const auto* src_h = hResult->Data();
        const auto* src_v = vResult->Data();
        for (std::uint32_t y = 0; y < h; y++) {
            for (std::uint32_t x = 0; x < w; x++) {
                const auto value = static_cast<std::uint8_t>(
                    clamp(std::hypot(static_cast<float>(*src_h), static_cast<float>(*src_v)), F_MIN, F_MAX));
                *(dst) = value;
                *(dst + 1) = value;
                *(dst + 2) = value;
                src_h++;
                src_v++;
                dst += 4;
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
