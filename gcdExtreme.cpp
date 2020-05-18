#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {

	if(b == 0) {
		return a;
	}

	return gcd(b, a%b);
}

long calculateG(int n) {

	long g = 0;

	for(int i = 1; i < n; i++) {
		for(int j = i+1; j <= n; j++) {
			g += gcd(i, j);
		}
	}

	return g;
}

int main() {

	int n;
	cin >> n;

	while(n != 0) {

		long ans = calculateG(n);

		cout << ans;

		cin >> n;

	}
}