#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class ISobel :
	public IFilter
{
public:
	~ISobel() override = default;
};

}
