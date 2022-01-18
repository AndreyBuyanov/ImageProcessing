#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class ICanny :
    public IFilter
{
public:
    ~ICanny() override = default;

    virtual void SetSigma(
        float sigma) = 0;

    virtual void SetLowThreshold(
        std::uint8_t lowThreshold) = 0;

    virtual void SetHighThreshold(
        std::uint8_t highThreshold) = 0;
};

}
