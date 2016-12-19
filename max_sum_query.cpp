/*
http://codeforces.com/problemset/problem/276/C
This is a terrible solution compared to counting parenthesis
*/

// sort the input
// count the occurance of each index
// sort freq table and multiply it witl dsorted input

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

  vector<uint32_t> arr;
  vector<uint32_t>::iterator iter;
  uint32_t ft[1000000] = {0};
  vector<uint32_t> nzft; //non zero ft

  uint32_t size, numq, cut;
  cin >>  size;
  cin >>  numq;

  for (uint32_t i = 0 ; i < size; i++) {
    uint32_t temp;
    cin >> temp;
    arr.push_back(temp);
  }
    

  sort(arr.begin(), arr.end());

  /*for(iter = arr.begin(); iter != arr.end(); iter++) {
    cout << *iter;
  }*/

  for (uint32_t i = 0 ; i < numq; i++) {
    uint32_t start, end;
    cin >> start >> end;
    if (start > size || end > size) {
      cout << "WHAAAAAT!";
    }
    for (uint32_t j = start ; j <= end; j++) {
      ft[j]++;
    }
  }
  
  for (uint32_t i = 1 ; i <= size; i++) {
    if (ft[i] > 0) {
      //cout <<" add " << i << " " << ft[i] << "\n" ;
      nzft.push_back(ft[i]);
    }
  }
  
  sort(nzft.begin(), nzft.end());

  //sort(&ft[1], &ft[size+1]);

  /*for (uint32_t i = 1 ; i <= size; i++) {
    cout  << ft[i];
  }*/

  uint64_t total = 0;
  /*
  for (uint32_t i = 1 ; i <= size; i++) {
    //cout << " mult " << arr[size -i] << " * " << ft[size -(i-1)] <<"\n";
    total += arr[size -i]*ft[size - (i-1)];
  }
  */
    
  for (uint32_t i = 1 ; i <= nzft.size(); i++) {
    //cout << "val: " << arr[size -i] << " freq " << nzft[nzft.size()-i] << "\n";

    total += arr[size -i]*nzft[nzft.size()-i];
  }

  cout << total;
}
