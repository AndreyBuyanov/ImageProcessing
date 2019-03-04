#pragma once

#include "ImageLib/IBitmap.hpp"

namespace ImageLib
{

class Bitmap :
	public IBitmap
{
public:
	Bitmap();
	Bitmap(
		const uint32_t width,
		const uint32_t height,
		const BitmapFormat format);
	Bitmap(
		BitmapInfo &info);

	~Bitmap();

	// IBitmap
	uint32_t Width() const override;
	uint32_t Height() const override;

	uint8_t* Data() override;
	const uint8_t* Data() const override;

	BitmapFormat Format() const override;

private:
	BitmapInfo m_BitmapInfo;
	bool m_Ownership;
	void Unload();
};

}