// Card Game

// Vova again tries to play some computer card game.
// The rules of deck creation in this game are simple. Vova is given an existing deck of n cards and a magic number k. The order of the cards in the deck is fixed. Each card has a number written on it; number ai is written on the i-th card in the deck.
// After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). So Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.
// Vova's new deck is considered valid iff the product of all numbers written on the cards in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, and now he wonders, how many ways are there to choose x and y so the deck he will get after removing x cards from the top and y cards from the bottom is valid?
// Input

// The first line contains two integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 10^9).

// The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9) — the numbers written on the cards.

// Output

// Print the number of ways to choose x and y so the resulting deck is valid.

// Sample Input 1

// 3 4
// 6 2 8

// Sample Output 1

// 4

// Sample Input 2

// 3 6
// 9 1 14

// Sample Output 2

// 1

#include<bits/stdc++.h>
using namespace std;

void getPrimeFactors(long n, unordered_map<int, int> &frequency) {

	while(n%2 == 0) {
		frequency[2]++;
		n /= 2;
	}
	for(int i = 3; i*i <= n; i += 2) {
		while(n%i == 0) {
			frequency[i]++;
			n /= i;
		}
	}

	if(n != 1) {
		frequency[n]++;
	}
}

bool isDivisible(unordered_map<int, int> vp, unordered_map<int, int> vq) {

	unordered_map<int, int> :: iterator it;
	for(it = vp.begin(); it != vp.end(); it++) {
		long prime = it->first;
		if(vq[prime] < vp[prime]) {
			return false;
		}
	}

	return true;
}

void incrementPrimeFactors(long n, unordered_map<int, int> vp, unordered_map<int, int> &vq) {

	unordered_map<int, int> :: iterator it;
	for(it = vp.begin(); it != vp.end(); it++) {
		long prime = it->first;
		while(n%prime == 0) {
			vq[prime]++;
			n /= prime;
		}
	}

	if(n != 1) {
		vq[n]++;
	}
}	

void decrementPrimeFactors(long n, unordered_map<int, int> vp, unordered_map<int, int> &vq) {

	// for(int i = 2; i*i <= n; i++) {
	// 	while(n%i == 0) {
	// 		frequency[i]--;
	// 		n /= i;
	// 	}
	// }

	// if(n != 1) {
	// 	frequency[n]--;
	// }

	unordered_map<int, int> :: iterator it;
	for(it = vp.begin(); it != vp.end(); it++) {
		long prime = it->first;
		while(n%prime == 0) {
			vq[prime]--;
			n /= prime;
		}
	}

	if(n != 1) {
		vq[n]--;
	}
}

long getValidDecks(long *ar, int n, long k) {

	unordered_map<int, int> vp;
	getPrimeFactors(k, vp);

	unordered_map<int, int> vq;

	long count = 0;
	int j = 0;
	for(int i = 0; i < n; i++) {
		
		while(j < n) {
			long curr = ar[j];
			// getPrimeFactors(curr, vq);
			incrementPrimeFactors(curr, vp, vq);

			if(isDivisible(vp, vq)) {
				count += n-j;
				decrementPrimeFactors(ar[i], vp, vq);
				decrementPrimeFactors(curr, vp, vq);
				// j++;
				break;
			}

			j++;
		}

	}

	return count;
}

int main() {

	int n;
	long k;
	cin >> n >> k;

	long *ar = new long[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	long ans = getValidDecks(ar, n, k);

	cout << ans << endl;

	delete [] ar;
	return 0;
}