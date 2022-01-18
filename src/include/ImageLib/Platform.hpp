#pragma once

#if defined(_MSC_VER)
#   define IMAGELIB_COMPILER_MSVC
#elif defined(__GNUC__)
#   define IMAGELIB_COMPILER_GCC
#elif defined(__clang__)
#   define IMAGELIB_COMPILER_CLANG
#endif

#if defined(_WIN32) && defined(_DLL)
#   if (!defined(IMAGELIB_DLL) && !defined(IMAGELIB_STATIC))
#       define IMAGELIB_DLL
#   endif
#endif

#if defined(_MSC_VER)
#   if defined(_WIN64)
#       define IMAGELIB_64_BIT
#   else
#       define IMAGELIB_32_BIT
#   endif
#elif (defined(__GNUC__) || defined(__clang__))
#   if defined(_WIN64)
#       define IMAGELIB_64_BIT
#   else
#       if defined(__LP64__)
#           define IMAGELIB_64_BIT
#       else
#           define IMAGELIB_32_BIT
#       endif
#   endif
#endif
