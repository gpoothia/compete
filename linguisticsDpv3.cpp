//http://codeforces.com/contest/667/problem/C
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 

enum suf {
  DONT_KNOW,
  NO,
  YES
}; 

suf s2[10000];
suf s3[10000];

suf finds3(const char* str, int n);

suf finds2(const char* str, int n) {
  if (n < 0) {
    return NO;
  }
  if (s2[n] != DONT_KNOW){
    return s2[n];
  }
  suf term0 = DONT_KNOW, term1 = DONT_KNOW ,term2 = DONT_KNOW;  
  
  term1 = finds3(str, n-2); 
  if ((n-3) >= 0) {
    bool needterm2 = strncmp(str+n-1,str+n-3,2);
    if (needterm2) {
      term2 = finds2(str, n-2);
    }    
    else {
      term2 = NO;
    }
  }
  if (term1 == YES || term2 == YES) {
    s2[n] = YES;
  }
  else {
    s2[n] = NO;
  }
  return s2[n];
}

suf finds3(const char* str, int n) {
  if (n < 0) {
    return NO;
  }
  if (s3[n] != DONT_KNOW){
    return s3[n];
  }
  suf term1 = DONT_KNOW ,term2 = DONT_KNOW;  
  term1 = finds2(str, n-3); 
  if ((n-5) >= 0) {
    bool needterm2 = strncmp(str+n-2,str+n-5,3);
    if (needterm2) {
      term2 = finds3(str, n-3); 
    }
    else {
      term2 = NO;
    }
  }
  if (term1 == YES || term2 == YES) {
    s3[n] = YES;
  }
  else {
    s3[n] = NO;
  }
  return s3[n];
}

int main() {
  string input;
  cin >> input;  
  for (int i = 0; i < 10000; i++) {
    if (i <= 5) 
      s2[i] = NO;
    else
      s2[i] = DONT_KNOW;

    if (i <= 6) 
      s3[i] = NO;
    else
      s3[i] = DONT_KNOW;
  }
  s2[6] = YES;
  s3[7] = YES;

  finds2(input.c_str(), input.length() -1);
  finds3(input.c_str(), input.length() -1);
  //findnumsuffix2(input.c_str(), input.length() -1) + findnumsuffix3(input.c_str(), input.length() -1); 
  vector<string> vec;
  
  
  for (int i = 6; i < input.length() ; i++) {
    if(s2[i] == YES) {
        vec.push_back(string(&input[i - 1], 2));
    } 
    if(s3[i] == YES) {
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
