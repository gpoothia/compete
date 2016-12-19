
#include <iostream>
using namespace std;


int main()
{
	int x;
	int numBits = 0;
	cin >> x;
	while( x > 0) {
		if (x %2) {
			numBits++;
		}
		x = x >> 1;
	}

	cout << numBits;
}
