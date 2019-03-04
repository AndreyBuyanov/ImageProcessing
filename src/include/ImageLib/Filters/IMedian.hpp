#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

class IMedian3 :
	public IFilter
{
public:
	virtual ~IMedian3() {}
};

}
}
