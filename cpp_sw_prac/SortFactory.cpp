#include "SortFactory.h"

Sortinterface*
Sortinterface::createSrot(std::string sortName)
{
	Sortinterface* si = nullptr;
	if (sortName == "Bubble")
	{
		si = new BubbleSortFactory;
	}
	return si;
}