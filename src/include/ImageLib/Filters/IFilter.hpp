#pragma once

#include "ImageLib/IBitmap.hpp"
#include "ImageLib/Events.hpp"

namespace ImageLib::Filters
{

class IFilter
{
public:
    virtual ~IFilter() = default;

    virtual void ProcessBitmap() = 0;

    virtual void SetBitmap(
        IBitmap* bitmap) = 0;

    virtual void RegisterProgressEventHandler(
        IProgressEventHandler* handler) = 0;
    virtual void RegisterFilterControlEventHandler(
        IFilterControlEventHandler* handler) = 0;

    [[nodiscard]] virtual std::string GetName() const = 0;
};

}
