#ifndef OUTPUT_CONTAINER_H
#define OUTPUT_CONTAINER_H

#include <iostream>
#include <string>

template <class T>
void outputContainer(T& myContainer)
{
	std::cout << "Size: " << myContainer.size() << "\n";

	int n = 0;
	typename T::iterator it;
	for (it = myContainer.begin(); it != myContainer.end(); ++it)
	{
		std::cout << n++ << ": " << *it << "\n";
	}
}

#endif
