#include "ImageLib/BitmapView.hpp"

#include "ImageLib/IBitmap.hpp"
#include "ImageLib/BitmapHelper.hpp"

namespace ImageLib
{

BitmapView::BitmapView(
    IBitmap* bitmap)
    : m_Bitmap(bitmap)
{
}

void BitmapView::SetPixel(
    uint32_t x,
    uint32_t y,
    uint32_t channel,
    uint8_t value)
{
    m_Bitmap->Data()[BitmapHelper::GetPixelPosition(m_Bitmap, x, y, channel)] = value;
}

uint8_t BitmapView::GetPixel(
    uint32_t x,
    uint32_t y,
    uint32_t channel) const
{
    return m_Bitmap->Data()[BitmapHelper::GetPixelPosition(m_Bitmap, x, y, channel)];
}

}
