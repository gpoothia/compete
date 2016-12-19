// http://codeforces.com/contest/629/problem/C

#include <iostream>

using namespace std;

int N[10000][10000];

int FindN(int i, int j) {

  if (i < 0|| j < 0 || i < j) {
    return 0;
  }

  if (N[i][j]  != -1) {
    return N[i][j];
  }

  if (i == j) {
    N[i][j] = 1;
  }
  else {
    N[i][j] = FindN(i-1, j+1) + FindN(i-1, j-1);
  }
  return  N[i][j];
}


int main() {

  // init to -1
  for (int i = 0; i< 100; i++) {
    for (int j = 0 ; j < 100; j++) {
        N[i][j] = -1;
    }
  }
  
  cout << FindN(4,2);

}

/*

((()
(()(
()((


*/
