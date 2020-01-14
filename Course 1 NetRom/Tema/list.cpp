#include <list>
#include <time.h>
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


	/* Homework */

	// Lower and upper bounds for RNG
	int upperLimit = 3500;
	int lowerLimit = 35;
	// Seed for rand()
	srand(time(0));

	// List3 contains all list1 elements
	std::list<int> list3(list1); 
	
	// Add list2 elements at the end of list3
	list3.splice(list3.end(), list2);
	
	// Add 100 random elements between 35 and 3500
	for (int i = 0; i < 100; i++) {
		list3.push_back(rand() % (upperLimit - lowerLimit + 1) + lowerLimit);
	}
	
	// Remove all non-prime elements
	for (auto it = list3.begin(); it != list3.end(); ++it) {
		int temp = *it;
		bool prime = true;
		
		for (int div = 2; div <= sqrt(temp); div += 2) {
			if (temp % div == 0) {
				prime = false;
				break;
			}
			/* we do this so we only check if number   
			   can be divided by 2 3 5 7 9 etc
			 */
			if (div == 2) {
				div = 1;
			}
		}
		// erase the number if it isn't prime
		if (prime == false) {
			it = list3.erase(it);
			// decrement iterator so we don't skip elements
			it--;
		}
		
	}

	std::cout << "\nList with only prime numbers:\n";
	outputContainer<std::list<int>>(list3);
}
