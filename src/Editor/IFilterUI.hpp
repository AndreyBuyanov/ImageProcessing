#pragma once

#include <QWidget>

#include "ImageLib/Filters/IFilter.hpp"

using ImageLib::Filters::IFilter;

class IFilterUI
{
public:
	virtual ~IFilterUI() {}

	virtual QWidget* GetUI() = 0;

	virtual IFilter* GetFilter() = 0;

	virtual void ApplyParams() = 0;
};