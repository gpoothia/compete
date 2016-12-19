using namespace std;
#include <map>
#include <iostream>

int main() {
  map<int, int> dum;
  dum[1] = 2;
  dum[10] = 11;
  
  map<int,int>::iterator it;
  for(it = dum.begin(); it != dum.end(); it++) {
    cout << "key " << it->first<< "value" << it->second<<"\n";
  }

}
