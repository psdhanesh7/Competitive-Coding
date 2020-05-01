// Divisors Of Factorial

// Given a number, find the total number of divisors of the factorial of the number.
// Since the answer can be very large, print answer modulo 10^9+7.
// Input

// The first line contains T, number of testcases.


// T lines follows each containing the number N.

// Output

// Print T lines of output each containing the answer.

// Constraints

// 1 <= T <= 500

// 0 <= N <= 50000

// Sample Input:

// 3
// 2
// 3
// 4

// Sample Output:

// 2
// 4
// 8




#include<iostream>
using namespace std;

long m = 1e9 + 7;

void createSieve(bool *sieve, int n) {

	for(int i = 0; i <= n; i++) {
		sieve[i] = true;
	}

	sieve[0] = false;
	sieve[1] = false;

	for(int i = 2; i*i <= n; i++) {
		if(sieve[i]) {
			for(int j = i; i*j <= n; j++) {
				sieve[i*j] = false;
			}
		}
	}

}

long getNoOfDivisorsOfFactorial(int n) {

	bool *sieve = new bool[n+1];
	createSieve(sieve, n);

	long count = 1;

	for(int i = 2; i <= n; i++) {
		if(sieve[i]) {
			int power = 0;
			int p = i;

			while(p <= n) {
				power += n/p;
				p *= i;
			}

			count = (count * (power + 1))%m;
		}
	}

	delete sieve;

	return count;
}

int main() {

	int t;
	cin >> t;

	while(t--) {

		int n;
		cin >> n;

		long ans = getNoOfDivisorsOfFactorial(n);

		cout << ans << endl;
	}
	
	return 0;
}