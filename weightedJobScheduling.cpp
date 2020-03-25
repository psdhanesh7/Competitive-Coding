
// Weighted Job Scheduling

// You are given N jobs where every job is represented as:
// 1.Start Time
// 2.Finish Time
// 3.Profit Associated
// Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
// Input

// The first line of input contains one integer denoting N.
// Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 

// Output

// Output one integer, the maximum profit that can be achieved.

// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di, p ≤ 10^6
// Sample Input

// 4
// 3 10 20
// 1 2 50
// 6 19 100
// 2 100 200

// Sample Output

// 250



#include<bits/stdc++.h>
using namespace std;

struct job {
	int startTime, finishTime;
	int profit;
};

int check(struct job *ar, int start, int end) {

	int ans, e = end-1;
	while(start <= e) {

		int mid = (start + e)/2;
		if(ar[end].startTime >= ar[mid].finishTime) {
			if(ar[mid+1].finishTime <= ar[end].startTime) {
				start = mid + 1;
			}
			else {
				return mid;
			}
		}
		else {
			e = mid - 1;
		}
	}

	return -1;
}

bool compare(job j1, job j2) {
	return j1.finishTime < j2.finishTime;
}

int getMaxProfit(job *ar, int n) {

	sort(ar, ar+n, compare);

	int *profit = new int[n];
	profit[0] = ar[0].profit;

	for(int i = 1; i < n; i++) {

		int option1 = profit[i-1];
		int option2 = ar[i].profit;

		int index = check(ar, 0, i);
		if(index != -1) {
			option2 += profit[index];
		}

		profit[i] = max(option1, option2);
	}

	int maxProfit = profit[n-1];
	delete [] profit;

	return maxProfit;
}

int main() {

	int n;
	cin >> n;

	job *ar = new job[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i].startTime >> ar[i].finishTime >> ar[i].profit;
	}

	int maxProfit = getMaxProfit(ar, n);

	cout << maxProfit << endl;

	delete [] ar;
	return 0;

}