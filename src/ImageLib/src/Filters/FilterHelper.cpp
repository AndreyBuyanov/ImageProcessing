#include "ImageLib/Filters/FilterHelper.hpp"

#include "ImageLib/BitmapHelper.hpp"

#include <numeric>
#include <algorithm>
#include <limits>

namespace ImageLib
{
namespace Filters
{

void FilterHelper::Convolution(
    IBitmap* source,
    const kernel_t& kernel,
    IProgressEventHandler* handler)
{
    std::unique_ptr<IBitmap> tempBitmap(
        BitmapHelper::CreateEdgeHandledBitmap(source));
    float k = 0.0f;
    for (const auto& row: kernel) {
        k += std::accumulate(row.begin(), row.end(), 0.0f);
    }
    k = (k == 0.0f) ? 1.0f : (1.0f / k);
    std::uint32_t pixelSize = 1;
    if (BitmapFormat::RGBA == source->Format()) {
        pixelSize = 4;
    }
    std::uint8_t* dst = source->Data();
    const std::uint8_t* src1 = tempBitmap->Data();
    const std::uint8_t* src2 = tempBitmap->Data() + (tempBitmap->Width() * pixelSize);
    const std::uint8_t* src3 = tempBitmap->Data() + (tempBitmap->Width() * pixelSize) * 2;
    for (std::uint32_t y = 0; y < source->Height(); y++) {
        for (std::uint32_t x = 0; x < source->Width(); x++) {
            for (std::uint32_t plane = 0; plane < pixelSize; plane++) {
                float c =
                    *(src1 + pixelSize * 0) * kernel[0][0] +
                    *(src1 + pixelSize * 1) * kernel[0][1] +
                    *(src1 + pixelSize * 2) * kernel[0][2] +
                    *(src2 + pixelSize * 0) * kernel[1][0] +
                    *(src2 + pixelSize * 1) * kernel[1][1] +
                    *(src2 + pixelSize * 2) * kernel[1][2] +
                    *(src3 + pixelSize * 0) * kernel[2][0] +
                    *(src3 + pixelSize * 1) * kernel[2][1] +
                    *(src3 + pixelSize * 2) * kernel[2][2];
                c *= k;
                *dst = static_cast<std::uint8_t>(clamp(c, F_MIN, F_MAX));
                src1++;
                src2++;
                src3++;
                dst++;
            }
        }
        if (handler) {
            handler->UpdateProgress(static_cast<std::int32_t>(static_cast<float>(y) / source->Height() * 100));
        }
        src1 += 2 * pixelSize;
        src2 += 2 * pixelSize;
        src3 += 2 * pixelSize;
    }
}

std::unique_ptr<IBitmap> FilterHelper::Grayscale(
    IBitmap* source,
    IProgressEventHandler* handler)
{
    std::unique_ptr<IBitmap> result(
        CreateBitmap(
            source->Width(),
            source->Height(),
            BitmapFormat::Grayscale));
    if (BitmapFormat::Grayscale == source->Format()) {
        const std::size_t size = source->Width() * source->Height();
        memcpy(result->Data(), source->Data(), size);
    } else if (BitmapFormat::RGBA == source->Format()) {
        const std::uint32_t w = source->Width();
		const std::uint32_t h = source->Height();
		const std::uint8_t *src = source->Data();
        std::uint8_t* dst = result->Data();
		for (std::uint32_t y = 0; y < h; y++) {
			for (std::uint32_t x = 0; x < w; x++) {
				const std::uint8_t gray = static_cast<std::uint8_t>(
					src[0] * 0.299f +
					src[1] * 0.587f + 
					src[2] * 0.114f);
				*dst = gray;
                dst++;
				src += 4;
			}
			if (handler) {
				handler->UpdateProgress(std::int32_t(float(y) / h * 100));
			}
		}
    }
    return result;
}

}
}
