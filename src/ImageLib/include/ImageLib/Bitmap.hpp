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
		uint32_t width,
		uint32_t height,
		BitmapFormat format);
	explicit Bitmap(
		BitmapInfo &info);

	~Bitmap() override;

	// IBitmap
	[[nodiscard]] uint32_t Width() const override;
    [[nodiscard]] uint32_t Height() const override;

    [[nodiscard]] uint8_t* Data() override;
	[[nodiscard]] const uint8_t* Data() const override;

    [[nodiscard]] BitmapFormat Format() const override;

private:
	BitmapInfo m_BitmapInfo;
	bool m_Ownership;
	void Unload() const;
};

}