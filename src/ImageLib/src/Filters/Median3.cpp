#include "ImageLib/Filters/Median3.hpp"
#include "ImageLib/ImageLib.hpp"

#include <memory>

using std::unique_ptr;

namespace ImageLib
{
namespace Filters
{

using ImageLib::CreateThread;

Median3::Median3() :
	m_Bitmap(nullptr),
	m_ProgressEventHandler(nullptr),
	m_FilterControlEventHandler(nullptr),
	m_Thread(CreateThread(this)) {}

void Median3::ProcessBitmap()
{
	m_Thread->Start();
}

void Median3::SetBitmap(
	IBitmap *bitmap)
{
	if (m_Thread->IsStopped()) {
		m_Bitmap = bitmap;
	}
}

void Median3::RegisterProgressEventHandler(
	IProgressEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_ProgressEventHandler = handler;
	}
}

void Median3::RegisterFilterControlEventHandler(
	IFilterControlEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_FilterControlEventHandler = handler;
	}
}

string Median3::GetName() const
{
    return "Median 3";
}

void Median3::Run()
{
	if (m_FilterControlEventHandler) {
		m_FilterControlEventHandler->FilterStarted();
	}

	if (m_Bitmap) {

		unique_ptr<IBitmap> tempBitmap(CreateBitmap(
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
			memcpy(dst, src, srcOffset);
			src += srcOffset;
			dst += srcOffset;
			dst += 4;
		}

		dst = m_Bitmap->Data();
		uint8_t *src1 = tempBitmap->Data();
		uint8_t *src2 = tempBitmap->Data() + tempBitmap->Width() * 4;
		uint8_t *src3 = tempBitmap->Data() + (tempBitmap->Width() * 4) * 2;

		uint8_t bubble[9] = { 0 };

		uint32_t x = 0, y = 0, i = 0;
		for (y = 0; y < h; y++) {
			if (m_Thread->IsStopped()) {
				break;
			}
			for (x = 0; x < w; x++) {
				for (i = 0; i < 3; i++) {
					bubble[0] = *(src1 + 4 * 0);
					bubble[1] = *(src1 + 4 * 1);
					bubble[2] = *(src1 + 4 * 2);
					bubble[3] = *(src2 + 4 * 0);
					bubble[4] = *(src2 + 4 * 1);
					bubble[5] = *(src2 + 4 * 2);
					bubble[6] = *(src3 + 4 * 0);
					bubble[7] = *(src3 + 4 * 1);
					bubble[8] = *(src3 + 4 * 2);

					int m, t, l;
					for (m = 0; m < 5; m++) {
						t = bubble[m];
						for (l = m + 1; l < 9; l++) {
							if (t > bubble[l]) {
								t = bubble[l];
								bubble[l] = bubble[m];
								bubble[m] = t;
							}
						}
					}

					*dst = bubble[4];
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
			src1 += 8;
			src2 += 8;
			src3 += 8;
			if (m_ProgressEventHandler) {
				m_ProgressEventHandler->UpdateProgress(int32_t(float(y) / h * 100));
			}
		}
	}

	if (m_FilterControlEventHandler) {
		m_FilterControlEventHandler->FilterFinished();
	}
}

}
}
