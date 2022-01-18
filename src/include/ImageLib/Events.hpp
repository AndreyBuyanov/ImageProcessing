#pragma once

#include "ImageLib/Types.hpp"

namespace ImageLib
{

class IProgressEventHandler
{
public:
    virtual ~IProgressEventHandler() = default;

    virtual void UpdateProgress(
        int32_t percent) = 0;
};

class IFilterControlEventHandler
{
public:
    virtual ~IFilterControlEventHandler() = default;

    virtual void FilterStarted() = 0;
    virtual void FilterFinished() = 0;
};

}
