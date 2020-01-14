#include "problema_voturi.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
// http://www.infoarena.ro/problema-majoritatii-votului

Se da o lista de candidati.
Se cere sa se determine daca exista vreun candidat care are vot majoritar (apare in lista de voturi de n/2 + 1 ori).

Observatie: Solutia trebuie sa aiba complexitate de timp O(n).
Follow-up: Implementati solutia avand complexitate spatiala O(1).
*/

void initVec(std::vector<std::string>& v)
{
	v.push_back("Viorel-Riceard Badea");
	v.push_back("Ramurel Pastrama");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Cojocaru Tom-Mac-Bil-Bob-Constantin");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Geniloni Sfecla");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Rudolf Pufulete");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Bred Pit");
	v.push_back("Cojocaru Tom-Mac-Bil-Bob-Constantin");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Ilegitim Vasile");
	v.push_back("Mos Nicolae Craciun");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Ilegitim Vasile");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Cojocaru Tom-Mac-Bil-Bob-Constantin");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Argentina Aristotel");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Puscas Marin");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Argentina Aristotel");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Joaca-Bine Mirel");
	v.push_back("Mos Nicolae Craciun");
	v.push_back("Joaca-Bine Mirel");
}

void problemaVot()
{
	std::vector<std::string> candidati; // initializat cu lista de candidati
	initVec(candidati);
	size_t nrTotal = candidati.size();

	bool found = false; // se seteaza true daca exista castigator
	std::string castigator; // se seteaza numele castigatorului
	int voturiCastigator = 0; // se seteaza numarul de voturi primite de castigator

	/*
		TODO: algoritm de cautare a castigatorului
	*/

	if (found)
	{
		std::cout << "A gastigat \"" << castigator << "\" cu " << voturiCastigator <<
					" voturi din " << nrTotal << std::endl;
	}
	else
	{
		std::cout << "Nu avem un numar majoritar de voturi" << std::endl;
	}
}
