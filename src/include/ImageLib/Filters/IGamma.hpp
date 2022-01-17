#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib::Filters
{

class IGamma :
	public IFilter
{
public:
	~IGamma() override = default;

	virtual void SetGamma(
		float gamma) = 0;
};

}
