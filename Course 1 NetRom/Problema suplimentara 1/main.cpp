#include <iostream>
#include <vector>

using namespace std;

int n, x, temp;
vector<int> numbers;

int binarySearch(vector <int> v, int find, int left, int right) {
	int mid = 0;

	// If number could not be found in array
	if (left > right) {
		return -1;
	}
	
	mid = (left + right) / 2;

	// Check if we landed on the key
	if (v[mid] == find) {
		return mid;
	}

	// Check if the right half is sorted
	if (v[mid] <= v[right]) {
		// Recursive call for the half the given number is in
		if (v[mid] <= find && find <= v[right]) {
			return binarySearch(v, find, mid + 1, right);
		}
		else {
			return binarySearch(v, find, left, mid - 1);
		}
	}

	// Check if the left half is sorted
	if (v[left] <= v[mid]) {
		// Recursive call for the half the given number is in
		if (v[left] <= find && find <= v[mid]) {
			return binarySearch(v, find, left, mid - 1);
		}
		else {
			return binarySearch(v, find, mid + 1, right);
		}
	}

}

int main()
{
	cout << "Input array size: ";
 	cin >> n;

	cout << "\nInput array: ";
	for (int i = 0; i < n; i++) {
		cin >> temp;
		numbers.push_back(temp);
	}

	cout << "\nInput number to be searched: ";
	cin >> x;

	temp = binarySearch(numbers, x, 0, numbers.size() - 1);

	if (temp != -1) {
		cout << "\nThe number is at position: " << temp + 1;
	}
	else {
		cout << "\nNumber could not be found.";
	}

	return 0;
}

