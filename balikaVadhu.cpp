
// Balika Vadhu- Problem

// Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan 
// and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. 
// But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the 
// other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
// The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is 
// calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to 
// generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum 
// happiness that can be generated by the two blessings he has.
// Input Specification

// First line consists of number of test cases t. Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.

// Output Specification

// Output consists of t lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.

// Constraint

// 1 <= t <= 50

// 1 <= length(b1) , length(b2) <= 100 

// 1 <= K <= 100

// Sample Input

// 2
// asdf
// asdf
// 3
// anandi
// jagya
// 3

// Sample Output

// 317
// 0



#include<bits/stdc++.h>
using namespace std;

int getMaxBlessingHelper(string s1, string s2, int k, int dp[][110][110]) {

	if(k == 0) {
		return 0;
	}

	if(s1 == "" || s2 == "") {
		return INT_MIN;
	}

	if(dp[s1.length()][s2.length()][k] != -1) {
		return dp[s1.length()][s2.length()][k];
	}

	int ans = 0;	
	int option1 = getMaxBlessingHelper(s1.substr(1), s2, k, dp);
	int option2 = getMaxBlessingHelper(s1, s2.substr(1), k, dp);
		
	ans = max(option1, option2);
	
	if(s1[0] == s2[0]) {

		int option3 =  getMaxBlessingHelper(s1.substr(1), s2.substr(1), k-1, dp);
		if(option3 != INT_MIN) {
			ans = max(s1[0] + option3, ans);
		}
	}
	dp[s1.length()][s2.length()][k] = ans;

	return ans;
}

int getMaxBlessing(string s1, string s2, int n) {

	int dp[110][110][110];
	for(int i = 0; i <= s1.length(); i++) {
		for(int j = 0; j <= s2.length(); j++) {
			for(int k = 0; k <= n; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	int ans = getMaxBlessingHelper(s1, s2, n, dp);
	if( ans == INT_MIN) {
		return 0;
	}

	return ans;
}

int main() {

	int t;
	cin >> t;
	while(t--) {

		string s1, s2;
		cin >> s1 >> s2;

		int k;
		cin >> k;

		int ans = getMaxBlessing(s1, s2, k);

		cout << ans << endl;
	}

	return 0;
}