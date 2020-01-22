//Find the largest sum subarray, ie a contigous sub array

#include<bits/stdc++.h>
using namespace std;

int kadanes(int *ar, int n)
{
	int currentSum = 0, bestSum = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		currentSum = currentSum + ar[i];
		if(bestSum < currentSum)
		{
			bestSum = currentSum;
		}
		if(currentSum < 0)
		{
			currentSum = 0;
		}
	}

	return bestSum;
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

	int largestSum = kadanes(ar, n);
	cout << largestSum << endl;

	delete [] ar;

	return 0;
}