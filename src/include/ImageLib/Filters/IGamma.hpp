#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

class IGamma :
	public IFilter
{
public:
	virtual ~IGamma() {}

	virtual void SetGamma(
		const float gamma) = 0;
};

}
}
