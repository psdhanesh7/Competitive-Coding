#include<bits/stdc++.h>
using namespace std;

long modExp(long a, long b, long c) {

	if(a == 0) {
		return 0;
	}
	if(b == 0) {
		return 1;
	}

	long ans;
	if(b%2 == 0 ){
		// b is even
		long smallAns = modExp(a, b/2, c);
		ans = (smallAns * smallAns)%c;
	}
	else {
		long smallAns = modExp(a, b-1, c);
		ans = (a%c);
		ans = (ans * smallAns)%c;
	}
	// To handle negative integers
	return ((ans + c)%c);
}

long modInverse(long n, long p) {

	return modExp(n, p-2, p);
}

long factorial(long n, long p) {

	if(p <= n) {
		return 0;
	}

	long r = -1;
	for(long i = n+1; i < p; i++) {
		r = (r * modInverse(i, p)) % p;
	}

	return r + p;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		long n, p;
		cin >> n >> p;

		long ans = factorial(n, p);

		cout << ans << endl;
	}

	return 0;
}