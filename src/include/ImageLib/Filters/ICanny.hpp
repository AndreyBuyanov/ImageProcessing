#pragma once

#include "ImageLib/Filters/IFilter.hpp"

namespace ImageLib
{
namespace Filters
{

class ICanny :
	public IFilter
{
public:
	virtual ~ICanny() {}

	virtual void SetSigma(
		const float sigma) = 0;

	virtual void SetLowThreshold(
		const std::uint8_t lowThreshold) = 0;

	virtual void SetHighThreshold(
		const std::uint8_t highThreshold) = 0;
};

}
}
