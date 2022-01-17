#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class IGrayscale :
	public IFilter
{
public:
	~IGrayscale() override = default;
};

}
