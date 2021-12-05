#pragma once

#include "ImageLib/IBitmap.hpp"

#include <memory>

namespace ImageLib
{

class BitmapHelper
{
public:
    static std::unique_ptr<IBitmap> CreateEdgeHandledBitmap(
        const IBitmap* source);
    static std::size_t GetPixelPosition(
        const IBitmap* bitmap,
        const std::uint32_t x,
        const std::uint32_t y,
        const std::uint32_t channel); /*noexcept(false)*/
};

}
