// http://codeforces.com/contest/742/problem/A

#include <iostream>
using namespace std;

int units_dig[] = { 6, 8, 4, 2};

int main() {
  int n;
  cin >> n;
  if (n == 0) 
    cout << 1;
  else
    cout << units_dig[n % 4]  ;  

}
