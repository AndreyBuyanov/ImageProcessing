#pragma once

#include <QWidget>

#include "ImageLib/Filters/IFilter.hpp"

class IFilterUI
{
public:
    virtual ~IFilterUI() = default;

    virtual QWidget* GetUI() = 0;

    virtual ImageLib::Filters::IFilter* GetFilter() = 0;

    virtual void ApplyParams() = 0;
};