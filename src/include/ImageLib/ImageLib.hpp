#pragma once

#include "ImageLib/Platform.hpp"
#include "ImageLib/Types.hpp"

#include <string>

#if defined(IMAGELIB_COMPILER_MSVC) && defined(IMAGELIB_DLL)
#	if defined(ImageLib_EXPORTS)
#		define ImageLib_API __declspec(dllexport)
#	else
#		define ImageLib_API __declspec(dllimport)
#	endif
#elif defined(IMAGELIB_COMPILER_GCC)
#	if defined (__GNUC__) && (__GNUC__ >= 4)
#		define ImageLib_API __attribute__ ((visibility ("default")))
#	else
#		define ImageLib_API
#	endif
#endif

using std::string;

namespace ImageLib
{

class IBitmap;
class IThread;
class IRunnable;

struct BitmapInfo;

enum class BitmapFormat;

ImageLib_API IBitmap* CreateBitmap(
	const uint32_t width,
	const uint32_t height,
	const BitmapFormat format);

ImageLib_API IBitmap* CreateBitmap(
	BitmapInfo &info);

ImageLib_API IBitmap* LoadBitmap(
	const string &fileName);

ImageLib_API bool SaveBitmap(
	IBitmap *bmp,
	const string &fileName);

ImageLib_API IThread* CreateThread(
	IRunnable *method);

namespace Filters {

class IInvert;
class IConvultion3x3;
class IGrayscale;
class IGamma;
class IMedian3;

ImageLib_API IInvert* CreateInvertFilter();

ImageLib_API IConvultion3x3* CreateConvultion3x3Filter();

ImageLib_API IGrayscale* CreateGrayscaleFilter();

ImageLib_API IGamma* CreateGammaFilter();

ImageLib_API IMedian3* CreateMedian3Filter();

}

}
