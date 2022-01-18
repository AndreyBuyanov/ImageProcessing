#include "ImageLib/Filters/Convolution3x3.hpp"
#include "ImageLib/ImageLib.hpp"

#include <memory>
#include <cstring>

#define NINT(f)   ((f >= 0) ? (int)(f + .5) : (int)(f - .5))
#define THRESH(d) ((d > 255) ? 255 : ((d < 0) ? 0 : d))

namespace ImageLib::Filters
{

Convolution3x3::Convolution3x3() :
    m_Bitmap(nullptr),
    m_ProgressEventHandler(nullptr),
    m_FilterControlEventHandler(nullptr),
    m_Thread(CreateThread(this)),
    m_Kernel(Kernel3x3()) {}

void Convolution3x3::ProcessBitmap()
{
    m_Thread->Start();
}

void Convolution3x3::SetBitmap(
    IBitmap *bitmap)
{
    if (m_Thread->IsStopped()) {
        m_Bitmap = bitmap;
    }
}

void Convolution3x3::RegisterProgressEventHandler(
    IProgressEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_ProgressEventHandler = handler;
    }
}

void Convolution3x3::RegisterFilterControlEventHandler(
    IFilterControlEventHandler *handler)
{
    if (m_Thread->IsStopped()) {
        m_FilterControlEventHandler = handler;
    }
}

std::string Convolution3x3::GetName() const
{
    return "Convolution 3x3";
}

void Convolution3x3::SetKernel(
    const Kernel3x3 &kernel)
{
    if (m_Thread->IsStopped()) {
        m_Kernel = kernel;
    }
}

void Convolution3x3::Run()
{
    if (m_FilterControlEventHandler) {
        m_FilterControlEventHandler->FilterStarted();
    }

    if (m_Bitmap) {

        std::unique_ptr<IBitmap> tempBitmap(CreateBitmap(
            m_Bitmap->Width() + 2,
            m_Bitmap->Height() + 2,
            m_Bitmap->Format()));

        const uint32_t w = m_Bitmap->Width();
        const uint32_t h = m_Bitmap->Height();

        uint8_t *dst = nullptr, *src = nullptr;

        src = m_Bitmap->Data();
        uint32_t srcOffset = w * 4;
        dst = tempBitmap->Data() + tempBitmap->Width() * 4;
        for (uint32_t i = 0; i < h; i++) {
            dst += 4;
            std::memcpy(dst, src, srcOffset);
            src += srcOffset;
            dst += srcOffset;
            dst += 4;
        }

        float fsum = m_Kernel.Sum();
        if (fsum == 0)
            fsum = 1;
        else
            fsum = 1 / fsum;

        dst = m_Bitmap->Data();
        uint8_t *src1 = tempBitmap->Data();
        uint8_t *src2 = tempBitmap->Data() + tempBitmap->Width() * 4;
        uint8_t *src3 = tempBitmap->Data() + (tempBitmap->Width() * 4) * 2;

        for (uint32_t y = 0; y < h; y++) {
            if (m_Thread->IsStopped()) {
                break;
            }
            for (uint32_t x = 0; x < w; x++) {
                for (int i = 0; i < 3; i++) {
                    float c = (
                        *(src1 + 4 * 0) * m_Kernel[0][0] +
                        *(src1 + 4 * 1) * m_Kernel[0][1] +
                        *(src1 + 4 * 2) * m_Kernel[0][2] +
                        *(src2 + 4 * 0) * m_Kernel[1][0] +
                        *(src2 + 4 * 1) * m_Kernel[1][1] +
                        *(src2 + 4 * 2) * m_Kernel[1][2] +
                        *(src3 + 4 * 0) * m_Kernel[2][0] +
                        *(src3 + 4 * 1) * m_Kernel[2][1] +
                        *(src3 + 4 * 2) * m_Kernel[2][2]);
                    *dst = static_cast<uint8_t>(THRESH(NINT(c * fsum)));
                    src1++;
                    src2++;
                    src3++;
                    dst++;
                }
                src1++;
                src2++;
                src3++;
                dst++;

            }
            if (m_ProgressEventHandler) {
                m_ProgressEventHandler->UpdateProgress(int32_t(float(y) / h * 100));
            }
            src1 += 8;
            src2 += 8;
            src3 += 8;
        }
    }

    if (m_FilterControlEventHandler) {
        m_FilterControlEventHandler->FilterFinished();
    }
}

}
