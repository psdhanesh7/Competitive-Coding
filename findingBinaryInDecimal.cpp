
// Finding Binary in Decimal
// Level MEDIUM
// Given an integer n, the task is to find the number of integers between 1 to n whose decimal number representation contain only 0s and 1s.
// Note : You have to return the count.
// Input Format :

// Line 1 : Integer n

// Constraints :
// 1  ≤  n  ≤  10^9
// Sample Input :

// 10

// Sample Output :

// 2

// Sample Output Explanation :
// Between 1 and 10 ,there are only 2 numbers having only 0 and 1 which are 1 and 10.


#include<bits/stdc++.h>
using namespace std;

pair<int, int> noOfDigits(int n) {

	int count = 0;
	int index = 0;

	int temp = n;

	while(n > 0) {

		int d = n%10;
		n /= 10;
		count++;

		if(d != 0 && d != 1) {
			index = count;
		}
	}

	int new_n = temp/pow(10, index);

	return make_pair(new_n, index);
}

int countOfNumbers(int n)
{
	// Write your code here
    pair<int, int> d = noOfDigits(n);

	int binaryCount = 0;
	int index = d.second;

	while(d.first > 0) {
		binaryCount += ((d.first % 10) * (1<<index));
        index++;
		d.first /= 10;
	}
	
	index = d.second;
	for(int i = index; i > 0; i--) {
		binaryCount += (1 << (i-1));
	}

	return binaryCount;
}

int main() {

	int n; 
	cin >> n;

	int ans = countOfNumbers(n);

	cout << ans << endl;

	return 0;
}