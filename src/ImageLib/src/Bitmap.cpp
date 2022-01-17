#include "ImageLib/Bitmap.hpp"

namespace ImageLib
{

Bitmap::Bitmap():
	m_BitmapInfo(BitmapInfo()),
	m_Ownership(false) {}

Bitmap::Bitmap(
	const uint32_t width,
	const uint32_t height,
	const BitmapFormat format) :
	m_BitmapInfo({ nullptr, width, height, format }),
	m_Ownership(true)
{
	uint32_t bpp = 0;
	switch (m_BitmapInfo.format)
	{
	case BitmapFormat::RGBA:
		bpp = 32;
		break;
	case BitmapFormat::Grayscale:
		bpp = 8;
		break;
    }
	if (bpp != 0) {
		m_BitmapInfo.data = new uint8_t[m_BitmapInfo.width * m_BitmapInfo.height * (bpp / 8)];
	}
}

Bitmap::Bitmap(
	BitmapInfo &info):
	m_BitmapInfo(info),
	m_Ownership(false) {}

Bitmap::~Bitmap()
{
	Unload();
}

uint32_t Bitmap::Width() const
{
	return m_BitmapInfo.width;
}
uint32_t Bitmap::Height() const
{
	return m_BitmapInfo.height;
}
uint8_t* Bitmap::Data()
{
	return m_BitmapInfo.data;
}
const uint8_t* Bitmap::Data() const
{
	return m_BitmapInfo.data;
}
BitmapFormat Bitmap::Format() const
{
	return m_BitmapInfo.format;
}

void Bitmap::Unload() const
{
	if (m_BitmapInfo.data && m_Ownership) {
		delete[] m_BitmapInfo.data;
	}
}

}