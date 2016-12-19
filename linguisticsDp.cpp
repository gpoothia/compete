//http://codeforces.com/contest/667/problem/C
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct suffixinfo {
  int numsuffix;
  bool two;
  bool three;
};

suffixinfo sinfo[10000];



//SuffixInfo[offset].numsuffix = SuffixInfo[offset].two ? SuffixInfo[offset - 2].numsiffix + SuffixInfo[offset].three ? SuffixInfo[offset  - 3].numsuffix

int findnumsuffix(const char* input, int offset) {
  if (sinfo[offset].numsuffix != -1) {
    return sinfo[offset].numsuffix;
  }
  int term2 =0, term3 =0;
  // Is 2 letter suffix acceptable at this offset
  if((offset >= 6) && strncmp(input + offset - 1, input + offset -3, 2)) {
    term2 = findnumsuffix(input, offset -2) + 1; 
    sinfo[offset].two = true;
  }
  // Is 3 letter suffix acceptable at this offset
  if((offset >= 7) && strncmp(input + offset -2 , input + offset - 5, 3)) {
    term3 = findnumsuffix(input, offset -3) + 1; 
    sinfo[offset].three = true;
  }

  return (sinfo[offset].numsuffix = term2 + term3);
}


int main() {
  string input;
  cin >> input;  
  for (int i = 0; i < 10000; i++) {
    sinfo[i].numsuffix = -1;
    sinfo[i].two = sinfo[i].three = false;
  }
  for (int i = 0; i <= 5 ; i++) {
    sinfo[i].numsuffix = 0;
    sinfo[i].two = sinfo[i].three = false;
  }


  findnumsuffix (input.c_str(), input.length() -1) ;
  vector<string> vec;
  
  for (int i = 0; i <= input.length() ; i++) {
      //cout << "offset " <<  i << " got numsuffix " << sinfo[i].numsuffix << "\n";
      if (sinfo[i].two) {
        vec.push_back(string(&input[i - 1], 2));
        //cout << string(&input[i - 2], 2) << "\n";
      } 
      
      if (sinfo[i].three) {
        vec.push_back(string(&input[i - 2], 3));
        //cout << string(&input[i - 3], 3) << "\n";
      } 
      
  }
  cout << vec.size() << "\n";
  std::sort (vec.begin(), vec.end());
  for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
    cout << *iter << "\n";
  }
}
