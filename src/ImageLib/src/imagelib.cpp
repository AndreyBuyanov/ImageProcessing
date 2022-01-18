#include "ImageLib/Bitmap.hpp"
#include "ImageLib/Thread.hpp"

#include "ImageLib/Filters/Invert.hpp"
#include "ImageLib/Filters/Convolution3x3.hpp"
#include "ImageLib/Filters/Grayscale.hpp"
#include "ImageLib/Filters/Gamma.hpp"
#include "ImageLib/Filters/Median3.hpp"
#include "ImageLib/Filters/Sobel.hpp"
#include "ImageLib/Filters/Roberts.hpp"
#include "ImageLib/Filters/Canny.hpp"

namespace ImageLib
{

IBitmap* CreateBitmap(
    uint32_t width,
    uint32_t height,
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
    const std::string &fileName)
{
    return nullptr;
}

bool SaveBitmap(
    IBitmap *bmp,
    const std::string &fileName)
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

IConvolution3x3* CreateConvolution3x3Filter()
{
    return new Convolution3x3();
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

ISobel* CreateSobelFilter()
{
    return new Sobel();
}

IRoberts* CreateRobertsFilter()
{
    return new Roberts();
}

ICanny* CreateCannyFilter()
{
    return new Canny();
}

}

}
