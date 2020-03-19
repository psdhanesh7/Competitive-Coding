// Knapsnack - Problem

// A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
// Space complexity should be O(n).
// Input Format :

// Line 1 : N i.e. number of items
// Line 2 : N Integers i.e. weights of items separated by space
// Line 3 : N Integers i.e. values of items separated by space
// Line 4 : Integer W i.e. maximum weight thief can carry

// Output Format :

// Line 1 : Maximum value V

// Constraints
// 1 <= N <= 10^4
// 1<= wi <= 100
// 1 <= vi <= 100
// Sample Input 1 :

// 4
// 1 2 4 5
// 5 4 8 6
// 5

// Sample Output :

// 13


#include<bits/stdc++.h>
using namespace std;

// int knapsack(int* weights, int* values, int n, int maxWeight) {

// 	int **dp = new int*[n+1];
// 	for(int i = 0; i <= n; i++) {
// 		dp[i] = new int[maxWeight+1];
// 	}

// 	for(int i = 0; i <= n; i++) {
// 		dp[i][0] = 0;
// 	}
// 	for(int i = 0; i <= maxWeight; i++) {
// 		dp[0][i] = 0;
// 	}

// 	for(int i = 1; i <= n; i++) {
// 		for(int j = 1; j <= maxWeight; j++) {

// 			dp[i][j] = dp[i-1][j];
// 			if(weights[i-1] <= j) {
// 				dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i][j]);
// 			}
// 		}
// 	}

// 	int ans = dp[n][maxWeight];

// 	for(int i = 0; i <= n; i++) {
// 		delete [] dp[i];
// 	}
// 	delete [] dp;

// 	return ans;

// }

int knapsack(int* weights, int* values, int n, int maxWeight) {

	int **dp = new int*[2];
	for(int i = 0; i <= 2; i++) {
		dp[i] = new int[maxWeight+1];
	}

	for(int i = 0; i < 2; i++) {
		dp[i][0] = 0;
	}
	for(int i = 0; i <= maxWeight; i++) {
		dp[0][i] = 0;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= maxWeight; j++) {

			dp[1][j] = dp[0][j];
			if(weights[i-1] <= j) {
				dp[1][j] = max(values[i-1] + dp[0][j-weights[i-1]], dp[0][j]);
			}
		}

		for(int j = 0; j <= maxWeight; j++) {
			dp[0][j] = dp[1][j];
		}
	}

	int ans = dp[1][maxWeight];

	for(int i = 0; i < 2; i++) {
		delete [] dp[i];
	}
	delete [] dp;

	return ans;

}

// Recursive solution

// int knapsack(int *weights, int *values, int n, int maxWeight, int **dp) {
	
// 	if (maxWeight == 0 || n == 0) {
// 		return 0;
// 	}

// 	if(dp[n][maxWeight] != -1) {
// 		return dp[n][maxWeight];
// 	}

// 	int ans = knapsack(weights, values, n-1, maxWeight, dp);
// 	if(maxWeight - weights[n-1] >= 0) {
// 		int option2 = values[n-1] + knapsack(weights, values, n-1, maxWeight - weights[n-1], dp)
// 		ans = max(option2, ans);
// 	}
// 	dp[n][maxWeight] = ans;

// 	return ans;
// }

// int knapsack(int* weights, int* values, int n, int maxWeight){

//   /* Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//   */


// 	int **dp = new int*[n+1];
// 	for(int i = 0; i <= n; i++) {
// 		dp[i] = new int[maxWeight+1];
// 		for(int j = 0; j <= maxWeight; j++) {
// 			dp[i][j] = -1;
// 		}
// 	}

// 	int ans = knapsack(weights, values, n, maxWeight, dp);

// 	for(int i = 0; i <= n; i++) {
// 		delete [] dp[i];
// 	}
// 	delete [] dp;

// 	return ans;
// }

int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}


