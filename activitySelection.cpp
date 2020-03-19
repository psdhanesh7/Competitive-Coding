
// Activity Selection
// Send Feedback
// You are given n activities with their start and finish times. Select the maximum number of activities that can be 
// performed by a single person, assuming that a person can only work on a single activity at a time.
// Input

// The first line of input contains one integer denoting N.

// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.
// Output

// Output one integer, the maximum number of activities that can be performed

// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Sample Input

// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9

// Sample Output

// 4



#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {										
	return p1.second <= p2.second;
}

int getMaxActivities(pair<int, int> *ar, int n) {

	sort(ar, ar+n, compare);
	// for(int i = 0; i < n; i++) {
	// 	cout << ar[i].first << " " << ar[i].second << endl;
	// }
	int ans = 1;
	int prev = 0;
	for(int i = 1; i < n; i++) {
		if(ar[i].first >= ar[prev].second) {
			ans++;
			prev = i;
		}
	}

	return ans;
}

int main() {

	int n;
	cin >> n;

	pair<int, int> *ar = new pair<int, int>[n];
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ar[i] = make_pair(x, y);
	}

	int ans = getMaxActivities(ar, n);
	cout << ans << endl;

	delete [] ar;

	return 0;
}