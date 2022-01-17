#include "ImageLib/Filters/Invert.hpp"
#include "ImageLib/ImageLib.hpp"

namespace ImageLib::Filters
{

using ImageLib::CreateThread;

Invert::Invert():
	m_Bitmap(nullptr),
	m_ProgressEventHandler(nullptr),
	m_FilterControlEventHandler(nullptr),
	m_Thread(CreateThread(this)) {}

void Invert::ProcessBitmap()
{
	m_Thread->Start();
}

void Invert::SetBitmap(
	IBitmap *bitmap)
{
	if (m_Thread->IsStopped()) {
		m_Bitmap = bitmap;
	}
}

void Invert::RegisterProgressEventHandler(
	IProgressEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_ProgressEventHandler = handler;
	}
}

void Invert::RegisterFilterControlEventHandler(
	IFilterControlEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_FilterControlEventHandler = handler;
	}
}

std::string Invert::GetName() const
{
    return "Invert";
}

void Invert::Run()
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
				pixel[0] = 255 - pixel[0];
				pixel[1] = 255 - pixel[1];
				pixel[2] = 255 - pixel[2];
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
