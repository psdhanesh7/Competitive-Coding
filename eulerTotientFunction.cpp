#include<iostream>
using namespace std;

void eulerPhi(int n) {

	int phi[n+1];

	// Initialiize each index of the array with the same no.
	for(int i = 1; i <= n; i++) {
		phi[i] = i;
	}

	// Start creating the sieve
	for(int i = 2; i <= n; i++) {
		if(phi[i] == i) { // If the no is prime, then value == index will be the condition
			phi[i] = phi[i] - 1; // Euler totient function of any prime no p = p-1
			for(int j = i*2; j <= n; j += i) {
				phi[j] = (phi[j] * (i-1))/i;
			}
		} 
	}

	for(int i = 1; i <= n; i++) {
		cout << i << " : " << phi[i] << endl;
	}
}

int main() {

	eulerPhi(20);

	return 0;
}