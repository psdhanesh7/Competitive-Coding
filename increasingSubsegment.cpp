// Increasing Subsegment
// Level EASY
// Gary has a sequence A, consisting of n integers.
// We'll call a sequence ai, ai + 1, ..., aj (1 ≤ i ≤ j ≤ n) a subsegment of the sequence a. The value (j - i + 1) denotes the length of the subsegment.
// Your task is to find the longest subsegment of a, such that it is possible to change at most one number (change one number to any integer you want) from the subsegment to make the subsegment strictly increasing. You need to return the length of the maximum subsegment that you can find by changing only one integer in the given sequence.
// Input Format :

// Line 1 : Integer n (1 ≤ n ≤ 10^5)
// Line 2 : n integers a1, a2, ..., an (1 ≤ ai ≤ 10^9)

// Output Format :

// You only need to return the length of the subsegment you find

// Sample Input :

// 4
// 1 4 3 4

// Sample Output :

// 4

// Sample Output Explanation :
// We'll change the first 4 in the array by 2, thus making the sequence : {1, 2, 3, 4}.


#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int n) {
	// Write your code here.
    pair<int, int> *dp = new pair<int, int>[n];
    
    dp[0].first = 1;
    dp[0].second = 1;
    
    for(int i = 1; i < n; i++) {
        
        if(a[i] > a[i-1]) {
            dp[i].first = dp[i-1].first + 1;
            dp[i].second = dp[i-1].second + 1;
        }
        else if(dp[i-1].first == dp[i-1].second) {
            dp[i].first = 1;
            dp[i].second = dp[i-1].second + 1;
        }
        else {
            dp[i].first = 1;
            dp[i].second = dp[i-1].first + 1;
        }
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

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = solve(a, n);

    cout << ans << endl;

    return 0;
}