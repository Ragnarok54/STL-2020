#include <list>
#include <iostream>

#include "outputContainer.h"

void listOps()
{
	std::list<int> list1{ 1, 2, 3, 4 };
	std::list<int> list2 = { 6, 7 };
	list2.push_front(5);
	list2.push_back(8);

	std::cout << "\n-> List 1: \n";
	outputContainer<std::list<int>>(list1);

	std::cout << "\n-> List 2: \n";
	outputContainer<std::list<int>>(list2);

	std::list<int>::iterator it = list1.begin();
	++it;	// pointing to second position

	/* transfer all elements of list2 at position 2 in list1 */
	list1.splice(it, list2);

	/* transfer element pointed by it in list1 to the beginning of list2 */
	list2.splice(list2.begin(), list1, it);

	std::cout << "\n-> After splice";
	std::cout << "\n List 1:\n";
	outputContainer<std::list<int>>(list1);

	std::cout << "\n List 2:\n";
	outputContainer<std::list<int>>(list2);
}
