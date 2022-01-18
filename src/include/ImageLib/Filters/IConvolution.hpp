#pragma once

#include "ImageLib/Filters/IFilter.hpp"

#include <array>
#include <numeric>

namespace ImageLib::Filters
{

struct Kernel3x3
{
    std::array<std::array<float, 3>, 3> kernel {};

    Kernel3x3(
        const float k11,
        const float k12,
        const float k13,
        const float k21,
        const float k22,
        const float k23,
        const float k31,
        const float k32,
        const float k33)
    {
        kernel = {{
            { k11, k12, k13 },
            { k21, k22, k23 },
            { k31, k32, k33 }
        }};
    }

    Kernel3x3() = default;

    [[nodiscard]] float Sum() const
    {
        float result = 0.0f;
        for (const auto &row: kernel) {
            result += std::accumulate(row.begin(), row.end(), 0.0f);
        }
        return result;
    }

    std::array<float, 3>& operator [] (const std::size_t index)
    {
        return kernel[index];
    }

    const std::array<float, 3>& operator [] (const std::size_t index) const
    {
        return kernel[index];
    }

};

class IConvolution3x3 :
    public IFilter
{
public:
    ~IConvolution3x3() override = default;

    virtual void SetKernel(
        const Kernel3x3 &kernel) = 0;
};

}
