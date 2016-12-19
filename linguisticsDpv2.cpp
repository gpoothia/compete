//http://codeforces.com/contest/667/problem/C
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 
int64_t ns2[10000];
int64_t ns3[10000];

int64_t findnumsuffix3(const char* str, int n);

int64_t findnumsuffix2(const char* str, int n) {
  if (n < 0) {
    return 0;
  }
  if (ns2[n] != -1){
    return ns2[n];
  }
  int64_t term1 = findnumsuffix3(str, n-2);
  int64_t term2 = 0;
  if ((n-3) >= 0) {
    bool needterm2 = strncmp(str+n-1,str+n-3,2);
    if (needterm2) {
      term2 = findnumsuffix2(str, n-2);
    }
  }
  ns2[n] = 1 + term1 + term2;
  cout << "ns2 at " << n << " is " << ns2[n] << "\n";
  return ns2[n]; 
}

int64_t findnumsuffix3(const char* str, int n) {
  if (n < 0) {
    return 0;
  }
  if (ns3[n] != -1){
    return ns3[n];
  }
  int64_t term1 = findnumsuffix2(str, n-3);
  int64_t term2 = 0;
  if ((n-5) >= 0) {
    bool needterm2 = strncmp(str+n-2,str+n-5,2);
    if (needterm2) {
      term2 = findnumsuffix3(str, n-3);
    }
  }
  ns3[n] = 1 + term1 + term2;
  cout << "ns3 at " << n << " is " << ns3[n] << "\n";
  return ns3[n]; 
}

int main() {
  string input;
  cin >> input;  
  for (int i = 0; i < 10000; i++) {
    if (i <= 5) 
      ns2[i] = 0;
    else
      ns2[i] = -1;

    if (i <= 6) 
      ns3[i] = 0;
    else
      ns3[i] = -1;
  }


  findnumsuffix2(input.c_str(), input.length() -1) + findnumsuffix3(input.c_str(), input.length() -1); 
  vector<string> vec;
  
  
  for (int i = 6; i < input.length() ; i++) {
    if(ns2[i] >0) {
        vec.push_back(string(&input[i - 1], 2));
    } 
    if(ns3[i] > 0) {
        vec.push_back(string(&input[i - 2], 3));
    } 
  }


  std::sort (vec.begin(), vec.end());
  vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
  cout << vec.size() << "\n";

  for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
    cout << *iter << "\n";
  }
}
