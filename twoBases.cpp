#include <iostream>
using namespace std;

long long calc(int digits, int base)
{
	long long sum;
	int nextDigit;
	sum = 0;
	for (int i = 0; i < digits; i++) {
		cin >> nextDigit;
		sum = sum*base + nextDigit;
	}
	return sum;
}

int main()
{
	int digits, base;
	long long x, y;
	cin >> digits >> base;
	x = calc(digits, base);
	cin >> digits >> base;
	y = calc(digits, base);
	if (x < y) 
		cout << "<";
	else if ( x > y)
		cout << ">";
	else
		cout << "=";
}

