#include "ImageLib/Filters/Gamma.hpp"
#include "ImageLib/ImageLib.hpp"

#include <cmath>

namespace ImageLib::Filters
{

using ImageLib::CreateThread;

Gamma::Gamma() :
	m_Bitmap(nullptr),
	m_ProgressEventHandler(nullptr),
	m_FilterControlEventHandler(nullptr),
	m_Thread(CreateThread(this)),
	m_Gamma(0.01f) {}

void Gamma::ProcessBitmap()
{
	m_Thread->Start();
}

void Gamma::SetBitmap(
	IBitmap *bitmap)
{
	if (m_Thread->IsStopped()) {
		m_Bitmap = bitmap;
	}
}

void Gamma::RegisterProgressEventHandler(
	IProgressEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_ProgressEventHandler = handler;
	}
}

void Gamma::RegisterFilterControlEventHandler(
	IFilterControlEventHandler *handler)
{
	if (m_Thread->IsStopped()) {
		m_FilterControlEventHandler = handler;
	}
}

std::string Gamma::GetName() const
{
    return "Gamma";
}

void Gamma::SetGamma(
	const float gamma)
{
	if (m_Thread->IsStopped()) {
		m_Gamma = gamma;
	}
}

void Gamma::Run()
{
	if (m_FilterControlEventHandler) {
		m_FilterControlEventHandler->FilterStarted();
	}

	if (m_Bitmap) {
		const float gamma = 1.0f / m_Gamma;
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
				pixel[0] = static_cast<uint8_t>(255.0f * powf(pixel[0] / 255.0f, gamma));
				pixel[1] = static_cast<uint8_t>(255.0f * powf(pixel[1] / 255.0f, gamma));
				pixel[2] = static_cast<uint8_t>(255.0f * powf(pixel[2] / 255.0f, gamma));
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
