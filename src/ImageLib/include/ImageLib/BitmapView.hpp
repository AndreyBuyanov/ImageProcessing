#pragma once

#include "ImageLib/IBitmap.hpp"

namespace ImageLib
{

class BitmapView
{
public:
    explicit BitmapView(
        IBitmap* bitmap);
    void SetPixel(
        uint32_t x,
        uint32_t y,
        uint32_t channel,
        uint8_t value) /*noexcept(false)*/;
    [[nodiscard]] uint8_t GetPixel(
        uint32_t x,
        uint32_t y,
        uint32_t channel) const /*noexcept(false)*/;
private:
    IBitmap* m_Bitmap;
};

}
