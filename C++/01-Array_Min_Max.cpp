// Program to find the minimum (or maximum) element of an array

#include <iostream>
#include <algorithm>

using namespace std;

// Driver Code
int main() {
	// Input array
	int a[] = { 1, 423, 6, 46, 34, 23, 13, 53, 4 };
	int n = sizeof(a) / sizeof(a[0]);

	// Implemented inbuilt function to sort array
	sort(a, a + n);

	// after sorting the value at 0th position will minimum
	// and nth position will be maximum
	cout << "min-" << a[0] << " max-" << a[n - 1] << endl;

	return 0;
}
