#include<bits/stdc++.h>
using namespace std;

int getMinDifference(int *ar, int n, int k) {

	sort(ar, ar+n);

	int small = ar[0]+k;
	int big = ar[n-1]-k;

	if(small > big) {
		int temp = small;
		small = big;
		big = temp;
	}

	for(int i = 1; i < n-1; i++) {
		int add = ar[i] + k;
		int sub = ar[i] - k;

		if(sub >= small || add <= big) {
			continue;
		}
		if(add-small <= big-sub) {
			big = add;
		}
		else {
			small = sub;
		}
	}

	return big - small;
}

int main() {

	int n, k;
	cin >> n >> k;

	int *ar = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int minDifference = getMinDifference(ar, n, k);

	cout << minDifference << endl;

	delete [] ar;
	return 0;
}