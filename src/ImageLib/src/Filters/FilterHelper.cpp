#include "ImageLib/Filters/FilterHelper.hpp"

#include "ImageLib/BitmapHelper.hpp"
#include "ImageLib/BitmapView.hpp"

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
    
    BitmapView dstView { source };
    BitmapView srcView { tempBitmap.get() };

    for (std::uint32_t y = 0; y < source->Height(); y++) {
        for (std::uint32_t x = 0; x < source->Width(); x++) {
            for (std::uint32_t channel = 0; channel < pixelSize; channel++) {
                float c
                    = srcView.GetPixel(x    , y    , channel) * kernel[0][0]
                    + srcView.GetPixel(x + 1, y    , channel) * kernel[0][1]
                    + srcView.GetPixel(x + 2, y    , channel) * kernel[0][2]
                    + srcView.GetPixel(x    , y + 1, channel) * kernel[1][0]
                    + srcView.GetPixel(x + 1, y + 1, channel) * kernel[1][1]
                    + srcView.GetPixel(x + 2, y + 1, channel) * kernel[1][2]
                    + srcView.GetPixel(x    , y + 2, channel) * kernel[2][0]
                    + srcView.GetPixel(x + 1, y + 2, channel) * kernel[2][1]
                    + srcView.GetPixel(x + 2, y + 2, channel) * kernel[2][2];
                c *= k;
                dstView.SetPixel(x, y, channel,
                    static_cast<std::uint8_t>(clamp(c, F_MIN, F_MAX)));
            }
        }
        if (handler) {
            handler->UpdateProgress(static_cast<std::int32_t>(static_cast<float>(y) / source->Height() * 100));
        }
    }
}

void FilterHelper::Convolution(
    IBitmap* source,
    const kernel2_t& kernel,
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

    BitmapView dstView { source };
    BitmapView srcView { tempBitmap.get() };

    for (std::uint32_t y = 0; y < source->Height(); y++) {
        for (std::uint32_t x = 0; x < source->Width(); x++) {
            for (std::uint32_t channel = 0; channel < pixelSize; channel++) {
                float c = srcView.GetPixel(x + 1, y + 1, channel) * kernel[0][0]
                    + srcView.GetPixel(x + 2, y + 1, channel) * kernel[0][1]
                    + srcView.GetPixel(x + 1, y + 2, channel) * kernel[1][0]
                    + srcView.GetPixel(x + 2, y + 2, channel) * kernel[1][1];
                c *= k;
                dstView.SetPixel(x, y, channel,
                    static_cast<std::uint8_t>(clamp(c, F_MIN, F_MAX)));
            }
        }
        if (handler) {
            handler->UpdateProgress(static_cast<std::int32_t>(static_cast<float>(y) / source->Height() * 100));
        }
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
