#pragma once

#include "ImageLib/Types.hpp"

namespace ImageLib
{

class IProgressEventHandler
{
public:
	virtual ~IProgressEventHandler() {}

	virtual void UpdateProgress(
		const int32_t percent) = 0;
};

class IFilterControlEventHandler
{
public:
	virtual ~IFilterControlEventHandler() {}

	virtual void FilterStarted() = 0;
	virtual void FilterFinished() = 0;
};

}
