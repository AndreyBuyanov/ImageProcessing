#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class IRoberts :
	public IFilter
{
public:
	~IRoberts() override = default;
};

}
