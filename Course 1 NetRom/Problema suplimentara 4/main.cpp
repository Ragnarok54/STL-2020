#include <fstream>
#include <map>

using namespace std;

int n, m, w, h, x, y, sheepCount = 0;
map<int, int> yardPos;

// Function to check if a sheep is inside a yard 
bool isInside(int width, int height, int yardX, int yardY, int sheepX, int sheepY) {
	if (yardX <= sheepX && sheepX <= yardX + width)
		if (yardY <= sheepY && sheepY <= yardY + height)
			return true;
	return false;
}

int main()
{
	ifstream f("ograzi.in");
	ofstream g("ograzi.out");

	f >> n >> m >> w >> h;

	// Store the yard positions
	for (int i = 0; i < n; i++) {
		f >> x >> y;
		yardPos.insert(make_pair(x, y));
	}

	for (int i = 0; i < m; i++) {
		f >> x >> y;
		
		// Check if the sheep
		for (auto it = yardPos.begin(); it != yardPos.end(); ++it) {
			if (isInside(w, h, (*it).first, (*it).second, x, y) == 1)
				sheepCount++;
		}
	}

	g << "The number of sheep is: " << sheepCount;
	return 0;
}

