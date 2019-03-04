#include "ImageLib/BitmapHelper.hpp"
#include "ImageLib/IBitmap.hpp"

namespace ImageLib
{

/*IBitmap* ExpandBitmap(
	IBitmap* src,
	uint32_t kernelSize)
{
	if (!src) {
		return nullptr;
	}
	if (src->Format() == BitmapFormat::Unknown) {
		return nullptr;
	}

	IBitmap *dst = CreateBitmap(
		src->Width() + kernelSize - 1, 
		src->Height() + kernelSize - 1, 
		src->Format());

	uint32_t halfKernel = kernelSize / 2;

	uint32_t srcStride = 0, dstStride = 0;

	switch (src->Format()) {
	case BitmapFormat::Grayscale:
		srcStride = src->Width();
		dstStride = dst->Width();
		break;
	case BitmapFormat::RGBA:
		srcStride = src->Width() * 4;
		dstStride = dst->Width() * 4;
		break;
	}

	uint8_t *srcData = nullptr;
	uint8_t *dstData = nullptr;
	for (int y = 0; y < halfKernel; y++) {
		srcData = src->Data() + y * srcStride;
		dstData = dst->Data() + (halfKernel - 1 - y) * dstStride + halfKernel;
		for (int x = 0; x < halfKernel; x++) {
			switch (src->Format()) {
			case BitmapFormat::Grayscale:
				dstData[0] = srcData[0];
				dstData -= 1;
				srcData += 1;
				break;
			case BitmapFormat::RGBA:
				dstData[0] = srcData[0];
				dstData[1] = srcData[1];
				dstData[2] = srcData[2];
				dstData[3] = srcData[3];
				dstData -= 4;
				srcData += 4;
				break;
			}
		}
	}

	for (int y = 0; y < halfKernel; y++) {
		srcData = src->Data() + y * srcStride;
		dstData = dst->Data() + (halfKernel - 1 - y) * dstStride + halfKernel;
		
	}

	return dst;
}*/

}