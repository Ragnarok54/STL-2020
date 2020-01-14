#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>

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

	// Homework 
	std::ifstream f("animals.in");
	std::ofstream g("animals.out");
	std::string currentAnimal;
	std::map < std::string, int > freq;

	// Reading from file and keeping count in a map
	while (f >> currentAnimal) {
		animals.push_back(currentAnimal);
		freq[currentAnimal]++;
	}
	
	g << "Vector after reading from file:";
	for (auto it = animals.begin(); it != animals.end(); ++it) {
		g << "\n" << *it;
	}

	// Used to save iterator with most occurence
	auto Max = freq.begin();
	for (auto it = freq.begin(); it != freq.end(); ++it) {
		if (it->second > Max->second) {
			Max = it;
		}
	}
	g << "\n\nMost occuring animal is: " << Max->first;
	
	// Sort so we can use unique
	sort(animals.begin(), animals.end());
	animals.erase( std::unique(animals.begin(), animals.end()), animals.end() );
	
	g << "\n\nVector after deleting duplicates:";
	for (auto it = animals.begin(); it != animals.end(); ++it) {
		g << "\n" << *it;
	}
}
