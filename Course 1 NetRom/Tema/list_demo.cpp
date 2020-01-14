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
	{}
};

int area(const rect& r)
{
	// TODO: calculate area: W x H = (x2-x1) * (y2-y1)
	int area = 0;
	
	area = abs( (r.x2 - r.x1) * (r.y2 - r.y1) );
	return area;
}


int perimeter(const rect& r)
{	
	int perimeter = 0;

	perimeter = (r.x2- r.x1) * 2 + (r.y2 - r.y1) * 2;

	return perimeter;
}

// TODO: define operator == based on the rectangle area
bool operator==(const rect& r1, const rect& r2)
{
	if (area(r1) == area(r2))
		return true;
	else
		return false;
}

// TODO: define operator < based on the rectangle area
bool operator<(const rect& r1, const rect& r2)
{	
	if (area(r1) < area(r2))
		return true;
	else
		return false;
}

// TODO: print rectangle content and area to cout
void print(const rect& r)
{
	std::cout << "Rect: ";
	std::cout << "A(" << r.x1 << ", " << r.y1<<"), ";
	std::cout << "B(" << r.x2 << ", " << r.y2<<")";
}

void outputList(std::list<rect>& lst)
{
	std::cout << "The list is:\n";
	// iterate through the container and display content
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		print(*it);
		std::cout << "\n";
	}
}

void listDemo()
{
	// TODO: Create 8 objects
	rect r1(1, 1, 0, 0);
	rect r2(1, 2, 3, 4);
	rect r3(11, 11, 0, 0);
	rect r4(15, 3, 2, 2);
	rect r5(7, 5, 4, 1);
	rect r6(0, 0, 5, 5);
	rect r7(3, 1, 2, 6);
	rect r8(6, 2, 9, 3);

	// TODO: Display the container
	std::list<rect> rectList;
	rectList.push_back(r1);
	rectList.push_back(r2);
	rectList.push_back(r3);
	rectList.push_back(r4);
	rectList.push_back(r5);
	rectList.push_back(r6);
	rectList.push_back(r7);
	rectList.push_back(r8);

	outputList(rectList);

	// Find rectangle with biggest area
	auto Max = rectList.begin();
	for (auto it = rectList.begin(); it != rectList.end(); ++it) {
		if (area(*it) > area(*Max)) {
			Max = it;
		}
		if (area(*it) == area(*Max) && perimeter(*it) > perimeter(*Max)) {
			Max = it;
		}
	}
	std::cout << "\nRectangle with biggest area is:\n";
	print(*Max);

	
	// use this to get the "lowest" x1, y2 coords
	int MinX = INT_MAX; 
	int MinY = INT_MAX;
	// use this to get the "biggest" x2, y1 coords
	int MaxX = INT_MIN;
	int MaxY = INT_MIN;
	/* the rectangle that will include all others
	   is of the form A(MinX, MaxY) B(MaxX, MinY)
	   considering that we get as input for a rect
	   the LEFT UPPER corner by x1 y1 and
	   the RIGHT LOWER corner by x2 y2
	 */

	for (auto it = rectList.begin(); it != rectList.end(); ++it) {
		// coords for point A
		if ((*it).x1 < MinX) {
			MinX = (*it).x1;
		}
		if ((*it).y1 > MaxY) {
			MaxY = (*it).y1;
		}

		// coords for point B
		if ((*it).x2 > MaxX) {
			MaxX = (*it).x2;
		}
		if ((*it).y2 < MinY) {
			MinY = (*it).y2;
		}
	}
	std::cout << "The rectangle that includes all others in the list is:\n";
	std::cout << "Rect: A(" << MinX << ", " << MaxY << "), B(" << MaxX << ", " << MinY << ")";
}
