#include <iostream>
#include <vector>
#include <string>

#include "outputContainer.h"

void vectorOps()
{
	std::vector<std::string> initialAnimals(3, "Cat");
	initialAnimals.insert(initialAnimals.begin(), "Dog");
	initialAnimals.insert(initialAnimals.end(), "Rabbit");
	initialAnimals.push_back("Bird");

	std::cout << "\n-> Initial animals : (Capacity: " << initialAnimals.capacity() << ")\n";
	outputContainer<std::vector<std::string>>(initialAnimals);

	std::vector<std::string> animals(initialAnimals);
	animals.emplace_back("Frog");
	animals.push_back("Tiger");
	animals.emplace_back("Cat");

	std::cout << "\n-> Animals: (Capacity: " << animals.capacity() << ")\n";
	outputContainer<std::vector<std::string>>(animals);

	std::vector<std::string>::iterator it = animals.begin();
	/* removes the first element from the vector */
	animals.erase(it);
	/* removes all the elements except last two */
	animals.erase(animals.begin(), animals.end() - 2);

	std::cout << "\n-> Reverse animals: \n";
	std::cout << "Size: " << animals.size() << " Capacity: " << animals.capacity() << "\n";
	for (std::vector<std::string>::reverse_iterator itr = animals.rbegin(); itr != animals.rend(); ++itr)
	{
		std::cout << *itr << " ";
	}
}
