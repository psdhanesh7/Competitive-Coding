// Prime with 3 factors
// Level MEDIUM
// We know that prime numbers are - positive integers that have exactly two distinct positive divisors. Now a ninja wants to find out numbers having 3 factors only.
// You are given an array A of n positive integers. For each of them determine - whether it has 3 factors or not.
// Input format :

// Line 1 : Integer n, size of the array
// Line 2 : Array elements (separated by space)

// Output format :

// Print n lines : i-th line should contain "YES" (without the quotes), if number Ai has 3 factors, and "NO" (without the quotes), if it hasn't

// Constraints :
// 1  ≤  n  ≤  10^5
// 1  ≤  Ai  ≤  10^12
// Sample Input 1 :

// 3
// 4  5  6

// Sample Output 1 :

// YES
// NO
// NO

// Sample test case explanation :
// The given test has three numbers. The first number 4 has exactly three divisors - 1, 2 and 4. Thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5), and the third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".


#include<bits/stdc++.h>
using namespace std;

bool isPrime(long  long n) {

	long long sq = sqrt(n);
	if(sq * sq != n) {
		return false;
	}

	// int count = 1;
	int i;
	for(i = 2; i*i < n; i++) {
		if(n%i == 0) {
			return false;
		}
	}
	if(i*i == n) {
		return true;
	}

	return false;

	
}

void findPrimes(long *ar, int n)  {

	for(int i = 0; i < n; i++) {
		if(isPrime(ar[i])) {
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}

// void generat

int main() {

	int n;
	cin >> n;

	long *ar = new long[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	findPrimes(ar, n);

	delete [] ar;
	return 0;
}