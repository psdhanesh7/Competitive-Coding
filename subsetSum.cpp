#include<iostream>
using namespace std;

bool sumPossible(int *ar, int n, int k, int **dp)
{

	if(k == 0) {
		return true;
	}

	if(k < 0 || n == 0) {
		return false;
	}

	if(dp[n][k] == 1) {
		return true;
	}
	else if(dp[n][k] == 0) {
		return false;
	}

	if(sumPossible(ar, n-1, k-ar[n-1], dp) || sumPossible(ar, n-1, k, dp)) {
		dp[n][k] = 1;
		return true;
	}

	dp[n][k] = 0;
	return false;

}

int main()
{
	int n;
	cin >> n;

	int *ar = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}

	int k;
	cin >> k;

	int **dp = new int*[n+1];
	for(int i = 0; i <= n; i++)
	{
		dp[i] = new int[k+1];
		for(int j = 0; j <= k; j++)
		{
			dp[i][j] = -1;
		}
	}

	if(sumPossible(ar, n, k, dp))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	for(int i = 0; i <= n; i++)
	{
		delete [] dp[i];
	}
	delete [] dp;
	delete [] ar;

	return 0;
}