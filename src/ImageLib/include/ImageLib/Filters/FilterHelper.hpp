#pragma once

#include "ImageLib/IBitmap.hpp"
#include "ImageLib/Types.hpp"
#include "ImageLib/Events.hpp"

#include <memory>

namespace ImageLib
{
namespace Filters
{

class FilterHelper
{
public:
    static void Convolution(
        IBitmap* source,
        const kernel_t& kernel,
        IProgressEventHandler* handler);
    
    static void Convolution(
        IBitmap* source,
        const kernel2_t& kernel,
        IProgressEventHandler* handler);

    static std::unique_ptr<IBitmap> Grayscale(
        IBitmap* source,
        IProgressEventHandler* handler);
};

const float F_MIN = static_cast<float>(std::numeric_limits<std::uint8_t>::min());
const float F_MAX = static_cast<float>(std::numeric_limits<std::uint8_t>::max());

template<typename T>
inline const T& clamp(const T& v, const T& lo, const T& hi)
{
    if (v < lo) {
        return lo;
    } else if (v > hi) {
        return hi;
    } else {
        return v;
    }
}

}
}
