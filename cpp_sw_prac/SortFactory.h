#pragma once
#include "Sortinterface.h"

class SortFactory
{
public:
	virtual ~SortFactory() = default;
public:
	virtual Sortinterface* createSort() = 0;
};

