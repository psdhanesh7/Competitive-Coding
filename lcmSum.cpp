#include<iostream>
using namespace std;

long long phi[100001];

void eulerPhi(long long n) {

	
	// Initialiize each index of the array with the same no.
	for(long long i = 1; i <= n; i++) {
		phi[i] = i;
	}

	// Start creating the sieve
	for(long long i = 2; i <= n; i++) {
		if(phi[i] == i) { // If the no is prime, then value == index will be the condition
			phi[i] = phi[i] - 1; // Euler totient function of any prime no p = p-1
			for(long long j = i*2; j <= n; j += i) {
				phi[j] = (phi[j] * (i-1))/i;
			}
		} 
	}

}

long long getLCMSum(int n) {

	long long sum = 1;
	for(int d = 1; d <= n; d++) {
		// cout << phi[d] << endl;
		if(n%d == 0) {
			sum += (phi[d] * d);
		}
	}

	sum = (sum * n)/2;

	return sum;
}

int main() {

	int n;
	cin >> n;

	eulerPhi(n);

	long long ans = getLCMSum(n);

	cout << ans << endl;

	return 0;
}