#pragma once

#include <cstdint>

namespace ImageLib
{

#if defined(IMAGELIB_DOUBLE_PRECISION)
typedef double Real;
#else
typedef float Real;
#endif

}
