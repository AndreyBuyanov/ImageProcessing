#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class IInvert :
	public IFilter
{
public:
	~IInvert() override = default;
};

}
