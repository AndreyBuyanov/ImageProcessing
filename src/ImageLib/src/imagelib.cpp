#include "ImageLib/Bitmap.hpp"
#include "ImageLib/Thread.hpp"

#include "ImageLib/Filters/Invert.hpp"
#include "ImageLib/Filters/Convultion3x3.hpp"
#include "ImageLib/Filters/Grayscale.hpp"
#include "ImageLib/Filters/Gamma.hpp"
#include "ImageLib/Filters/Median3.hpp"

#include "FreeImage.h"

namespace ImageLib
{

IBitmap* CreateBitmap(
	const uint32_t width,
	const uint32_t height,
	const BitmapFormat format)
{
	return new Bitmap(width, height, format);
}

IBitmap* CreateBitmap(
	BitmapInfo &info)
{
	return new Bitmap(info);
}

IBitmap* LoadBitmap(
	const string &fileName)
{
	return nullptr;
}

bool SaveBitmap(
	IBitmap *bmp,
	const string &fileName)
{
	return false;
}

IThread* CreateThread(
	IRunnable *method)
{
	return new Thread(method);
}

namespace Filters {

IInvert* CreateInvertFilter()
{
	return new Invert();
}

IConvultion3x3* CreateConvultion3x3Filter()
{
	return new Convultion3x3();
}

IGrayscale* CreateGrayscaleFilter()
{
	return new Grayscale();
}

IGamma* CreateGammaFilter()
{
	return new Gamma();
}

IMedian3* CreateMedian3Filter()
{
	return new Median3();
}

}

}
