#include<bits/stdc++.h>
using namespace std;

int getMinFareHelper(int **fares, int busNo, int cityNo, int n, int m) {

	if(cityNo == n) {
		return 0;
	}

	if(busNo >= m || busNo < 0) {
		return INT_MAX;
	}

	int option1 = getMinFareHelper(fares, busNo, cityNo+1, n, m);
	int option2 = getMinFareHelper(fares, busNo+1, cityNo+1, n, m);
	int option3 = getMinFareHelper(fares, busNo-1, cityNo+1, n, m);
	
	int ans = fares[cityNo][busNo] + min(option1, min(option2, option3));

	return ans;
}

int getMinFareIterative(int **fares, int n, int m) {

	int **dp = new int*[n];
	for(int i = 0; i < n; i++) {
		dp[i] = new int[m];
	}

	for(int i = 0; i < m; i++) {
		dp[n-1][i] = fares[n-1][i];
	}

	for(int i = n-2; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {

			dp[i][j] = dp[i+1][j];
			if(j+1 < m) {
				dp[i][j] = min(dp[i+1][j+1], dp[i][j]);
			}
			if(j-1 >= 0) {
				dp[i][j] = min(dp[i+1][j-1], dp[i][j]);
			}

			dp[i][j] += fares[i][j];
		}
	}

	int ans = dp[0][0];
	for(int i = 0; i < m; i++) {
		ans = min(dp[0][i], ans);
	}

	for(int i = 0; i < n; i++) {
		delete [] dp[i];
	}
	delete [] dp;

	return ans;
}
int getMinFare(int **fares, int n, int m) {

	int ans = INT_MAX;
	for(int i = 0; i < m; i++ ) {
		ans = min(getMinFareIterative(fares, i, 0, n, m), ans);
	}

	return ans;
}

int main() {

	int n, m;
	cin >> n >> m;

	int **fares = new int*[n];
	for(int i = 0; i < n; i++) {
		fares[i] = new int[m];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> fares[i][j];
		}
	}

	int ans = getMinFareIterative(fares, n, m);

	cout << ans << endl;

	for(int i = 0; i < n; i++) {
		delete [] fares[i];
	}
	delete [] fares;

	return 0;
}