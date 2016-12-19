//http://codeforces.com/contest/667/problem/A
using namespace std;

#include <iostream>
#include <math.h>

int main() {
  float d,h,v,e;
  cin  >> d;
  cin  >> h;
  cin  >> v; 
  cin  >> e;
  cout << d << h << v << e;
 /* 
  float ror = e*22/7*pow(d/2,2); //rate of rain
  cout << "ror =" << ror  << "\n";
  if (v <= ror) {
    cout << "NO";
    exit(0);
  }
  
  float rod = v - ror; //rate of decrease
  float origvol = h*pow(d/2,2);  
  cout << "YES\n" << (origvol/rod);
*/
  float ror = e;
  float dr = v/(3.14159*pow(d/2,2));//drink rate
  if (dr <= ror ) {
    cout << "NO";
    exit(0);
  }
  float rod = dr - ror; //rate of decrease
  cout << "YES\n" << h/rod; 
}
