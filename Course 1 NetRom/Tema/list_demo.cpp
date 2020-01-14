#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

// Define a structure for a rectangle: x1, y1, x2, y2
// Define a constructor for the rectangle
struct rect
{
	int x1, y1;
	int x2, y2;

	rect(int a, int b, int c, int d) :
		x1(a),
		y1(b),
		x2(c),
		y2(d)
	{
	}
};

int area(const rect& r)
{
	// TODO: calculate area: W x H = (x2-x1) * (y2-y1)
	int area = 0;
	return area;
}

// TODO: define operator == based on the rectangle area
bool operator==(const rect& r1, const rect& r2)
{
	return true;
}

// TODO: define operator < based on the rectangle area
bool operator<(const rect& r1, const rect& r2)
{
	return true;
}

// TODO: print rectangle content and area to cout
void print(const rect& r)
{
	std::cout << "Rect: " << std::endl;
}

void outputList(std::list<rect>& lst)
{
	// iterate through the container and display content
}

void listDemo()
{
	// TODO: Create 8 objects

	// TODO: Display the container

	// TODO: Find if there are any rectangles with the same area
}
