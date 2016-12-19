
#include <iostream>
using namespace std;


int main() {
	int num;
	int lastInflPt = 0;
	int lastInflec = 0; // -1, 0 or +1
	int maxRange = 0;		
	int a[10000];
	cin >> num;
	for (int i = 0; i < num ; i++) {
		cin >> a[i];
		if (i > 0) {
			int currDel = a[i] - a[i-1];
			if (currDel == 0) {
				continue;
			}
			if (currDel != lastInflec) {
				lastInflec = currDel;
				continue;
			}
			else {
				lastInflec = currDel;
				if ( (i -lastInflPt  ) > maxRange) {
					maxRange = i -lastInflPt ;
				}
				lastInflPt = i -1;	
			}
		}
	}
				if ( (num  -lastInflPt ) > maxRange) {
					maxRange = num  -lastInflPt;
				}
	cout << maxRange;

}
