#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class IMedian3 :
    public IFilter
{
public:
    ~IMedian3() override = default;
};

}
