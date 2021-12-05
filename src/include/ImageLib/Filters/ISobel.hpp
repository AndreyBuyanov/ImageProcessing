#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

class ISobel :
	public IFilter
{
public:
	virtual ~ISobel() {}
};

}
}
