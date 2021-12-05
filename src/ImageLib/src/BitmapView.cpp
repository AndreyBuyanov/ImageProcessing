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
    const uint32_t x,
    const uint32_t y,
    const uint32_t channel,
    const uint8_t value)
{
    m_Bitmap->Data()[BitmapHelper::GetPixelPosition(m_Bitmap, x, y, channel)] = value;
}

uint8_t BitmapView::GetPixel(
    const uint32_t x,
    const uint32_t y,
    const uint32_t channel) const
{
    return m_Bitmap->Data()[BitmapHelper::GetPixelPosition(m_Bitmap, x, y, channel)];
}

}
