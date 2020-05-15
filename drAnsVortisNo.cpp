#include<iostream>
using namespace std;

#define MAX 1000001

bool isVortisNo(long n) {

	int prev = n%2;
	n /= 2;

	while(n > 0) {
		int b = n%2;
		if(b == prev && b == 1) {
			return true;
		}
		prev = b;
		n /= 2;
	}

	return false;
}

int* getVortisCount(long *ar, int n) {
	int *vortisNo = new int[n];

	vortisNo[0] = isVortisNo(ar[0]) ? 1 : 0;
	for(int i = 1; i < n; i++) {
		vortisNo[i] = isVortisNo(ar[i]) ? vortisNo[i-1] + 1 : vortisNo[i-1];
	}

	for(int i = 0; i < n; i++) {
		cout << vortisNo[i] << " ";
	}
	cout << endl;
	return vortisNo;
}

int vortisNosInGivenRange(int *vortisNo, int l, int r) {
	if(l == 0) {
		return vortisNo[r];
	}
	return vortisNo[r] - vortisNo[l-1];
}

int main () {

	int n, q;
	cin >> n >> q;

	long *ar = new long[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int *vortisNo = getVortisCount(ar, n);

	while(q--) {
		
		int l, r;
		cin >> l >> r;

		int ans = vortisNosInGivenRange(vortisNo, l-1, r-1);

		cout << ans << endl;
	}

	delete [] ar;
	delete [] vortisNo;
	return 0;
}