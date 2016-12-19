/*
http://codeforces.com/contest/629/problem/A
Smarter approach - avoid 2 D memory space
Keep running track od Cs per row and col and for each new C accumulate how many new pairs it creates
*/

#include <iostream>
#include <string.h>
using namespace std;

const char* dot = ".";
const char* C = "C";

int main() {
  int n;
  int arr[100][100];
  char line[100];
  int countpairs = 0;

  cin >> n;
  // Load the 2D  array
  for (int i =0; i< n ; i++) {
    cin >> line;
    for (int j = 0; j < n ; j++) {
      if (!strncmp(&line[j], dot, 1)) {
        //cout << "0";
        arr[i][j] = 0;
      } else if (!strncmp(&line[j], C, 1)) {
        arr[i][j] = 1;
        //cout << "1";
      }
      else {
        cout << "error";
      }
    }
  }

  // Count pairs in rows
  for (int i =0 ; i < n; i++) {
    int onesinrow = 0;
    for (int j = 0; j < n ; j++) {
      if (arr[i][j] == 1) 
        onesinrow++;
    }
    if (onesinrow)
      countpairs += onesinrow * (onesinrow -1)/2;
  }
  // Count pairs in cols
  for (int i =0 ; i < n; i++) {
    int onesincol = 0;
    for (int j = 0; j < n ; j++) {
      if (arr[j][i] == 1) 
        onesincol++;
    }
    if (onesincol)
      countpairs += onesincol * (onesincol -1)/2;
  }


  cout << countpairs;
}
