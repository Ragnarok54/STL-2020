#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>

#include "outputContainer.h"

void setOps()
{
	std::set<std::string> setOfCities;
	setOfCities.insert("Sibiu");
	setOfCities.insert("Craiova");
	setOfCities.insert("Bucuresti");
	setOfCities.insert("Craiova");

	std::cout << " Set Of Cities: \n";
	outputContainer<std::set<std::string>>(setOfCities);

	std::vector<std::string> newCities{ "Iasi", "Sibiu", "Timisoara" };
	newCities.push_back("Slatina");
	newCities.emplace_back("Bals");

	std::cout << "\n Vector of New Cities: \n";
	outputContainer<std::vector<std::string>>(newCities);

	setOfCities.insert(newCities.begin(), newCities.begin() + 4);
	std::cout << "\n Set Of Cities after insert: \n";
	outputContainer<std::set<std::string>>(setOfCities);

	std::set<std::string>::iterator it = setOfCities.find("Sibiu");
	if (it != setOfCities.end())
	{
		setOfCities.erase(it);
	}

	setOfCities.erase("Slatina");

	std::cout << "\n Set Of Cities after erase: \n";
	outputContainer<std::set<std::string>>(setOfCities);

	// Homework
	std::ifstream f("cities.in");
	std::string currentCity;

	// Read cities from file
	while (f >> currentCity) {
		setOfCities.insert(currentCity);
	}
	std::cout << "\n List after adding cities from file:\n";
	outputContainer<std::set<std::string>>(setOfCities);

	// Remove all cities that start with letter T
	for (auto it = setOfCities.begin(); it != setOfCities.end(); ++it) {
		if ((*it)[0] == 'T') {
			it = setOfCities.erase(it);
			it--;
		}
	}
	std::cout << "\n After erase:\n";
	outputContainer<std::set<std::string>>(setOfCities);

	// Count cities that end with the letter "a"
	int lastA = 0;
	for (auto it = setOfCities.begin(); it != setOfCities.end(); ++it) {
		if ((*it).back() == 'a') {
			lastA++;
		}
	}
	std::cout << "\n Number of cities that end with 'a' is " << lastA<<"\n";
}
