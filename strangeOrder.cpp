// Strange order

// Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
// Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
// Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
// Input format

// Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.

// Output format

// Print n integers — array a .

// Sample Input:

// 5

// Sample Output:

// 5 4 2 3 1

// Explanation

// It's needed 4 iterations to create array a:
// Add 5
// Add 4 and 2
// Add 3
// Add 1


#include<bits/stdc++.h>
using namespace std;

#define MAX 10000000

int lowestPrimeDivisor[MAX];

void sieve(int n) {

	for(int i = 1; i <= n; i++) {
		lowestPrimeDivisor[i] = i;
	}

	for(int i = 2; i <= n; i++) {
		if(lowestPrimeDivisor[i] == i) {
			for(int j = 2; i*j <= n; j++) {
				lowestPrimeDivisor[i*j] = i;
			}
		}
	}
}

int main() {

	int n; 
	cin >> n;

	sieve(n);

	bool *marked = new bool[n+1]();
	vector<int> final;

	for(int i = n; i > 0; i--) {
		if(!marked[i]) {

			int x = i;
			int lpd = lowestPrimeDivisor[i];
			vector<int> y;

			while(lpd != 1) {

				for(int j = i; j > 0; j -= lpd) {
					if(!marked[j]) {
						y.push_back(j);
						marked[j] = true;
					}
				}

				while(x%lpd == 0) {
					x /= lpd;
				}

				lpd = lowestPrimeDivisor[x];

			}
			sort(y.begin(), y.end(), greater<int>());

			vector<int> :: iterator it;
			for(it = y.begin(); it != y.end(); it++) {
				final.push_back(*it);
			}
		}
	}
    final.push_back(1);

	vector<int> :: iterator it;
	for(it = final.begin(); it != final.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	delete [] marked;
	return 0;
}