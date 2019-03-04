#pragma once

#include "ImageLib/ImageLib.hpp"

using std::string;

namespace ImageLib
{

enum class BitmapFormat
{
	Unknown = 0,
	Grayscale,
	RGBA
};

enum class ImageFormat
{
	Unknown = 0,
	BMP,
	JPEG,
	PNG,
	GIF
};

struct BitmapInfo
{
	uint8_t* data;
	uint32_t width;
	uint32_t height;
	BitmapFormat format;

	BitmapInfo(
		uint8_t* _data,
		const uint32_t _width,
		const uint32_t _height,
		const BitmapFormat _format) :
		data(_data),
		width(_width),
		height(_height),
		format(_format) {}

	BitmapInfo() :
		data(nullptr),
		width(0),
		height(0),
		format(BitmapFormat::Unknown) {}
};

class IBitmap
{
public:
	virtual ~IBitmap() {}

	virtual uint32_t Width() const = 0;
	virtual uint32_t Height() const = 0;

	virtual uint8_t* Data() = 0;
	virtual const uint8_t* Data() const = 0;

	virtual BitmapFormat Format() const = 0;
};

}