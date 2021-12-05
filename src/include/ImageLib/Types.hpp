#pragma once

#include <cstdint>
#include <array>

namespace ImageLib
{

#if defined(IMAGELIB_DOUBLE_PRECISION)
typedef double Real;
#else
typedef float Real;
#endif

using kernel_t = std::array<std::array<Real, 3>, 3>;
using kernel2_t = std::array<std::array<Real, 2>, 2>;

}
