#include<bits/stdc++.h>
using namespace std;

#define width 200

int maxWidth(int *x, int *y, int n) {

	
}

int main() {

	int n;
	cin >> n;

	int *x = new int[n];
	int *y = new int[n];

	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> y[i];
	}

	int ans = maxWidth(x, y, n);

	cout << ans << endl;

	delete [] x;
	delete [] y;

	return 0;
}