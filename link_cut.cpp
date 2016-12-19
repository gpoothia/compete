#include <iostream>
using namespace std;

# To avoid overflowing k^n:
# How can we evaluate k^n <= r without risking overflow?
# We can instead evaluate k^(n-1) <=  r/k

int main(){
	int64_t l,r,k, kpow = 1;
	cin >> l >> r >> k;
	bool found = false;
	if (kpow <= r && kpow >=l) {
		cout << kpow << " ";
		found = true;
	}
		
	while (kpow <= r/k) {
		//cout << "checking kpow "<<  kpow <<  "\n";
		kpow = kpow * k;
		if (kpow >= l) {
			cout << kpow << " ";
			found = true;
		}
	}
	if (!found) {
		cout << "-1";
	} 
}
