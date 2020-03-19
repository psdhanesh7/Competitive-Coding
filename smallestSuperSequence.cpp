// Smallest Super-Sequence
// Send Feedback
// Given two strings S and T, find and return the length of their smallest super-sequence.
// A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
// Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
// Input Format:

// Line 1 : A string
// Line 2: Another string

// Output Format:

// Length of the smallest super-sequence of given two strings. 

// Sample Input:

// ab
// ac

// Sample Output:

// 3

// Sample Output Explanation:

// Their smallest super-sequence can be "abc" which has length=3.


#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int smallestSuperSequenceIterative(char str1[], int len1, char str2[], int len2) {

	int **dp = new int*[len1+1];
	for(int i = 0; i <= len1; i++) {
		dp[i] = new int[len2+1];
	}

	for(int i = 0; i <= len1; i++) {
		dp[i][0] = i;
	}
	for(int i = 0; i <= len2; i++) {
		dp[0][i] = i;
	}

	for(int i = 1; i <= len1; i++ ) {
		for(int j = 1; j <= len2; j++) {
			if(str1[i-1] == str2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	for(int i = 0; i <= len1; i++) {
		delete [] dp[i];
	}
	delete [] dp;

	return dp[len1][len2];
}

int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

	if(len1 == 0) {
		return len2;
	}
	if(len2 == 0) {
		return len1;
	}

	int ans;
	if(str1[0] == str2[0]) {
		ans = 1 + smallestSuperSequence(str1+1, len1-1, str2+1, len2-1);
	}
	else {
		int option1 = smallestSuperSequence(str1+1, len1-1, str2, len2);
		int option2 = smallestSuperSequence(str1, len1, str2+1, len2-1);

		ans = 1 + min(option1, option2);
	}

	return ans;
}


int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequenceIterative(str1, len1, str2, len2);
    cout<<min_len << endl;
    return 0;
}
