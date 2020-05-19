// Loot Houses

// A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
// Input Format

// Line 1 : An integer N 
// Line 2 : N spaced integers denoting money in each house

// Output Format

//  Line 1 : Maximum amount of money looted

// Input Constraints

// 1 <= n <= 10^4
// 1 <= A[i] < 10^4

// Sample Input :

// 6
// 5 5 10 100 10 5

// Sample Output 1 :

// 110



#include <iostream>
using namespace std;

int getMaxMoney(int arr[], int n, int prevLooted, int *dp[]){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 


	if(n == 0) {
		return 0;
	}

	if(dp[prevLooted][n] != -1) {
		return dp[prevLooted][n];
	}

	int option1 = getMaxMoney(arr, n-1, 0, dp);
	int option2 = 0;
	if(!prevLooted) {
		option2 = getMaxMoney(arr, n-1, 1, dp) + arr[n-1];
	}

	int ans = max(option1, option2);
	dp[prevLooted][n] = ans;

	return ans;
}

int getMaxMoney(int arr[], int n) {

	// int *dp = new int[n+1];
	int *dp[2];
	dp[0] = new int[n+1];
	dp[1] = new int[n+1];

	for(int i = 0; i <= n; i++) {
		dp[0][i] = -1;
		dp[1][i] = -1;
	}

	int ans = getMaxMoney(arr, n, 0, dp);

	delete [] dp[0];
	delete [] dp[1];

	return ans;
}


int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n) << endl;
}

