

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100000];
int last[100010];

int main() {
	int num;
	cin >> num;
	int ans = 0;
	for (int i = 0; i < num ; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 100010; i++) {
		last[i] = -1;	
	}
	for (int i = 0; i < num ; i++) {
		
		// find l for seqn ending at i
		int l1 = -1, l2 = -1, l3 = -1, l4 = -1;
		if (a[i] + 2 <= 100002) {
			l1 =  last[a[i] +2];
		}
		if (a[i] - 2 >= 0) {
			l2 = last[a[i] -2];
		}
		if (a[i] + 1 <= 100001) {
			l3 =  last[a[i] +1];
		}
		if (a[i] - 1 >= 0) {
			l4 = last[a[i] -1];
		}
		vector<int> v ;
		v.push_back(l1);
		v.push_back(l2);
		v.push_back(l3);
		v.push_back(l4);
		//cout << "i " << i << " l1/2/3/4 " << l1 << l2 << l3 << l4 << "\n";
		std::sort(v.begin(), v.end());
		//cout << "i " << i << " l1/2/3/4 " << v[0] << v[1] << v[2] << v[3] << "\n";
		int l;
		if (v[2] == -1) {
			l = -1; // seqn from start	
			
		}
		else {
			l = v[2] ;
		}	
			
		ans = max(ans, (i - l));
		last[a[i]] = i;
	}	
	 cout << ans;
}

