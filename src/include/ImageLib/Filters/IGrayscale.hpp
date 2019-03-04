#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

class IGrayscale :
	public IFilter
{
public:
	virtual ~IGrayscale() {}
};

}
}
