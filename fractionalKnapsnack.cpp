// Fractional Knapsack

// You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
// Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
// Note: You can hire a previously hired worker without paying him again.
// Input

// The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.

// Output

// Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.

// Constraints
// 1 ≤ N, T, X, Y ≤ 10^5
// 1 ≤ D ≤ 10^11
// Sample Input

// 3 3
// 1 1 1
// 2 2 2
// 3 1 5

// Sample Output

// 3



#include<bits/stdc++.h>
using namespace std;

struct worker {

	int arrival;
	int hiringCost;
	int speed;
};

bool compare(worker w1, worker w2) {

	if(w1.arrival == w2.arrival) {

		if(w1.speed == w2.speed) {
			return w1.hiringCost < w2.hiringCost;
		}
		else {
			return w1.speed > w2.speed;
		}
	}
	else {
		return w1.arrival < w2.arrival;
	}
}

int getMinCost(worker *ar, int n, long d) {

	sort(ar, ar+n, compare);

	int minCost = ar[0].hiringCost;
	worker prevWorker = ar[0];

	for(int i = 1; i < n; i++) {
		if(ar[i].arrival == ar[i-1].arrival) {
			continue;
		}
		if(ar[i].speed > prevWorker.speed) {
			d -= (ar[i].arrival - prevWorker.arrival) * prevWorker.speed;
			if(d <= 0) {
				break;
			}

			minCost += ar[i].hiringCost;
			prevWorker = ar[i];
		}
		
	}

	return minCost;
}

int main() {

	int n;
	long d;
	cin >> n >> d;

	worker *ar = new worker[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i].arrival >> ar[i].hiringCost >> ar[i].speed;
	}

	int minCost = getMinCost(ar, n, d);

	cout << minCost << endl;

	delete [] ar;
	return 0;

}