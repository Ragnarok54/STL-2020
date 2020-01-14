#include <map>
#include <fstream>
#include <string>

#include "outputContainer.h"

void outputMap(std::map<std::string, std::string>& myMap)
{
	int n = 0;
	std::cout << "Size: " << myMap.size() << "\n";
	for (const auto it : myMap)
	{
		std::cout << n++ << ": ";
		std::cout << it.first << " " << it.second << "\n";
	}
}

void mapOps()
{
	std::map<std::string, std::string> places{ { "Craiova", "Dolj" },{ "Brasov", "Brasov" },{ "Iasi", "Iasi" } };
	places.insert(std::pair<std::string, std::string>("Ploiesti", "Prahova"));
	places.insert(std::make_pair("Sibiu", "Sibiu"));	// make_pair() can also be used for creating a pair

	//outputContainer<map<string, string>>(places);
	std::cout << "\n Places: \n";
	outputMap(places);

	auto craiovaIt = places.find("Craiova");	// points to entry having key = "Craiova"
	auto sibiuIt = places.find("Sibiu");		// points to entry having key = "Sibiu"

	/* newPlaces contains all entries pointed by iterator craiovaIt to iterator sibiuIt */
	std::map<std::string, std::string> newPlaces(craiovaIt, sibiuIt);
	std::cout << "\n New Places: \n";
	outputMap(newPlaces);

	/* does not insert the pair as newPlaces already contains key = "Craiova" */
	newPlaces.insert(std::make_pair("Craiova", "Dolj"));
	newPlaces["Craiova"] = "";
	newPlaces.insert(std::make_pair("Craiova", "Dolj"));
	newPlaces.insert(std::make_pair("Constanta", "Constanta"));

	std::cout << "\n New Places after insert: \n";
	outputMap(newPlaces);

	places.erase(craiovaIt);
	newPlaces.erase("Craiova");

	newPlaces.insert(places.begin(), places.end());
	std::cout << "\n New Places after erase and insert: \n";
	outputMap(newPlaces);

	// Homework
	std::ifstream f("places.in");
	std::string currentPlace;
	std::string city;

	int cities = 0;
	while (f >> currentPlace) {
		if ( isdigit(currentPlace.back()) ) {
			cities = currentPlace.back() - '0';
			currentPlace = currentPlace.substr(0, currentPlace.length() - 2);
		}
		else {
			cities = 1;
		}
		
		for (int i = 0; i < cities; i++) {
			f >> city;
			newPlaces.insert(make_pair(city, currentPlace));
		}
	}
	std::cout << "\n Places after reading from file:\n";
	outputMap(newPlaces);

	std::cout << "\n\nPlaces in Dolj: ";
	for (auto it = newPlaces.begin(); it != newPlaces.end(); ++it) {
		if ((*it).second == "Dolj") {
			std::cout << (*it).first<<" ";
		}
	}

	std::cout << "\n\nPlaces in Oltenia: ";
	for (auto it = newPlaces.begin(); it != newPlaces.end(); ++it) {
		if ((*it).second == "Dolj" || (*it).second == "Olt" || (*it).second == "Mehedinti" || (*it).second == "Vrancea" || (*it).second == "Gorj") {
			std::cout << (*it).first << " ";
		}
	}
	std::cout << "\n";
}
