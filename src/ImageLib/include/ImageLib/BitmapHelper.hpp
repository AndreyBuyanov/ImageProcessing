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
        std::uint32_t x,
        std::uint32_t y,
        std::uint32_t channel); /*noexcept(false)*/
};

}
