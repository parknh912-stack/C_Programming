#include <iostream>
#include "User.h"
#include "Bubblesort.h"
#include <memory>
#include "SortFactory.h"

int main()
{
	//shared_ptr
	std::shared_ptr<User> user = std::make_shared<User>();
	

	SortFactory sortFactory;
	sortFactory = new BubbleSortFactory;
	sortFactory = sortFactory->createSort();

	sortFactory = new QuickSortFactory;
	sort = sortFactory->createSort();

	/*auto Sortinterface = sortFatcoty.createSort("Quick");
	sort = sortFatcoty.createSort("Bubble");*/

	Sortinterface * sort;
	sort = new Bubblesort;

	user->setStrategy(sort);
	user->sortMember();

	//delete user;
	//delete sort;
	//
	//

}