#include "ImageLib/Filters/Grayscale.hpp"
#include "ImageLib/ImageLib.hpp"

namespace ImageLib
{
namespace Filters
{

using ImageLib::CreateThread;

Grayscale::Grayscale() :
	m_Bitmap(nullptr),
	m_ProgressEventHandler(nullptr),
	m_FilterControlEventHandler(nullptr),
	m_Thread(CreateThread(this)) {}

void Grayscale::ProcessBitmap()
{
	m_Thread->Start();
}

void Grayscale::SetBitmap(
	IBitmap *bitmap)
{
	if (m_Thread->IsStopped()) {
		m_Bitmap = bitmap;
	}
}

void Grayscale::RegisterProgressEventHandler(
	IProgressEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_ProgressEventHandler = handler;
	}
}

void Grayscale::RegisterFilterControlEventHandler(
	IFilterControlEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_FilterControlEventHandler = handler;
	}
}

string Grayscale::GetName() const
{
    return "Grayscale";
}

void Grayscale::Run()
{
	if (m_FilterControlEventHandler) {
		m_FilterControlEventHandler->FilterStarted();
	}

	if (m_Bitmap) {
		const uint32_t w = m_Bitmap->Width();
		const uint32_t h = m_Bitmap->Height();
		const uint32_t p = w * 4;
		uint8_t *bits = m_Bitmap->Data();
		for (uint32_t y = 0; y < h; y++) {
			if (m_Thread->IsStopped()) {
				break;
			}
			uint8_t *pixel = bits;
			for (uint32_t x = 0; x < w; x++) {
				const uint8_t gray = static_cast<uint8_t>(
					pixel[0] * 0.299f +
					pixel[1] * 0.587f + 
					pixel[2] * 0.114f);
				pixel[0] = pixel[1] = pixel[2] = gray;
				pixel += 4;
			}
			if (m_ProgressEventHandler) {
				m_ProgressEventHandler->UpdateProgress(int32_t(float(y) / h * 100));
			}
			bits += p;
		}
	}

	if (m_FilterControlEventHandler) {
		m_FilterControlEventHandler->FilterFinished();
	}
}

}
}
