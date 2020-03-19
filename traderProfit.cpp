// Trader Profit

// Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
// Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
// The stock prices are given in the form of an array A for n days.
// Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
// Input Format

// The first line of input contains an integer q denoting the number of queries.

// The first line of each test case contains a positive integer k, denoting the number of transactions. 

// The second line of each test case contains a positive integer n, denoting the length of the array A.

// The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.

// Constraints

// 1<=q<=100

// 0<k<10

// 2<=n<=30

// 0<=elements of array A<=1000

// Output Format

// For each query print the maximum profit earned by Mike on a new line. 

// Sample Input

// 3
// 2
// 6
// 10 22 5 75 65 80
// 3
// 4
// 20 580 420 900
// 1
// 5
// 100 90 80 50 25

// Sample Output

// 87
// 1040
// 0

#include<bits/stdc++.h>
using namespace std;

int getMaxProfitDp(int *ar, int n, int k, int onGoing, int ***dp) {

	if(k == 0 || n == 0) {
		return 0;
	}

	if(dp[onGoing][n][k] != INT_MIN) {
		return dp[onGoing][n][k];
	}

	int option1 = getMaxProfitDp(ar+1, n-1, k, onGoing, dp);
	int option2;
	if(onGoing == 1) {
		option2 = ar[0] + getMaxProfitDp(ar+1, n-1, k-1, 0, dp);
	}
	else {
		option2 = getMaxProfitDp(ar+1, n-1, k, 1, dp) - ar[0];
	}

	int ans = max(option1, option2);
	dp[onGoing][n][k] = ans;

	return ans;
}

int getMaxProfit(int *ar, int n, int k) {

	int **dp[2];
	for(int i = 0; i < 2; i++) {
		dp[i] = new int*[n+1];
		for(int j = 0; j <= n; j++) {
			dp[i][j] = new int[k+1];
		}
	}

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			dp[0][i][j] = INT_MIN;
			dp[1][i][j] = INT_MIN;
		}
	}

	int ans = getMaxProfitDp(ar, n, k, 0, dp);

		for(int i = 0; i < 2; i++) {
		for(int j = 0; j <= n; j++) {
			delete [] dp[i][j];
		}
	}
	delete [] dp[0];
	delete [] dp[1];

	return ans;

}

// int getMaxProfitIterative(int *ar, int n, int k) {

	// int **dp[2];
	// for(int i = 0; i < 2; i++) {
	// 	dp[i] = new int*[n+1];
	// 	for(int j = 0; j <= n; j++) {
	// 		dp[i][j] = new int[k+1];
	// 	}
	// }

// 	for(int i = 0; i <= n; i++) {
// 		dp[0][i][0] = 0;
// 		dp[1][i][0] = 0;
// 	}
// 	for(int i = 0; i <= k; i++) {	
// 		dp[0][0][i] = 0;
// 		dp[1][0][i] = 0;
// 	}

// 	for(int i = 1; i <= n; i++) {
// 		for(int j = 1; j <= k; j++) {
// 			dp[0][i][j] = max(dp[0][i-1][j], dp[0][i-1][j] - ar[n-i]);
// 			dp[1][i][j] = max(dp[1][i-1][j], dp[1][i-1][j-1] + ar[n-i]);
// 		}
// 	}
	
// 	int ans = dp[0][n][k];

	// for(int i = 0; i < 2; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		delete [] dp[i][j];
	// 	}
	// }
	// delete [] dp[0];
	// delete [] dp[1];

// 	return ans;
// }


int main() {

	int t;
	cin >> t;

	while(t--) {
		int k, n;
		cin >> k >> n;

		int *ar = new int[n];
		for(int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		int ans = getMaxProfit(ar, n, k);

		cout << ans << endl;

		delete [] ar;
	}

	return 0;
}