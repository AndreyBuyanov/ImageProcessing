#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

class IInvert :
	public IFilter
{
public:
	virtual ~IInvert() {}
};

}
}
