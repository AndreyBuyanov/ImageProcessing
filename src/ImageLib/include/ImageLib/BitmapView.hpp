#pragma once

#include "ImageLib/IBitmap.hpp"

namespace ImageLib
{

class BitmapView
{
public:
    BitmapView(
        IBitmap* bitmap);
    void SetPixel(
        const uint32_t x,
        const uint32_t y,
        const uint32_t channel,
        const uint8_t value) /*noexcept(false)*/;
    uint8_t GetPixel(
        const uint32_t x,
        const uint32_t y,
        const uint32_t channel) const /*noexcept(false)*/;
private:
    IBitmap* m_Bitmap;
};

}
