http://codeforces.com/contest/667/problem/C
#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> strset;

void findsuffix(const char* input, int len, const char* lastsuffix, int lslen) {

  //Consume size 2 suffix
  if (len >=7 && (lslen != 2 || 
                  strncmp(input + len - 2, lastsuffix, 2) !=0)) {
    string newsuffix = string(&input[len -2], 2);
    strset.insert(newsuffix);
    findsuffix(input, len -2, newsuffix.c_str(), 2);
  }
  //Consume size 3 suffix
  if (len >=8 && (lslen != 3 || 
                  strncmp(input + len - 3, lastsuffix, 3) !=0)) {
    string newsuffix = string(&input[len - 3], 3);
    strset.insert(newsuffix);
    findsuffix(input, len -3, newsuffix.c_str(), 3);
  }


}


int main() {
  string input;
  cin >> input;  
  findsuffix (input.c_str(), input.length(), NULL, 0);
  set<string>::iterator iter;
  for (iter = strset.begin(); iter != strset.end(); iter++) {
    cout << *iter << "\n";
  }
}
