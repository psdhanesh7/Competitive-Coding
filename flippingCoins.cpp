#include<bits/stdc++.h>
using namespace std;


int solve(int arr[],int n)
{
	// Write your code here.
    pair<int, int> *dp = new pair<int, int>[n];
    
    if(arr[0] == 0) {
        dp[0].first = 0;
        dp[0].second = 1;
    }
    else {
        dp[0].first = 1;
        dp[0].second = 1;
    }
    
    for(int i = 1; i < n; i++) {
        
        if(arr[i] == 1) {
            dp[i].first = dp[i-1].first + 1;
            dp[i].second = dp[i-1].second + 1;
        }
        else if(arr[i-1] == 1 && dp[i-1].first == dp[i-1].second){
            dp[i].first = dp[i-1].first;
            dp[i].second = dp[i-1].second + 1;
        }
        else if(arr[i-1] == 1) {
            dp[i].first = dp[i-1].first;
            dp[i].second = dp[i-1].first + 1;
        }
        else {
            dp[i].first = dp[i-1].first;
            dp[i].second = dp[i-1].second + 1;
        }

        // cout << i << " : " << dp[i].first << ", " << dp[i].second << endl;
    }
    
    int maxLength = 0;
    for(int i = 0; i < n; i++) {
        maxLength = max(maxLength, dp[i].second);
    }
    
    delete [] dp;
    return maxLength;
}

int main() {

	int n;
	cin >> n;

	int arr[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = solve(arr, n);

	cout << ans << endl;

	return 0;

}