#include<bits/stdc++.h>
using namespace std;

int bestProduct(int *arr, int n)
{
	int bestSubarrayProduct = INT_MIN;
	int maxEnding = 1, minEnding = 1;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] > 0)
		{
			maxEnding *= arr[i];
			minEnding = min(1, minEnding*arr[i]);
		}
		else if(arr[i] < 0)
		{
			int temp = maxEnding;
			maxEnding = max(1, minEnding * arr[i]);
			minEnding = temp * arr[i];
		}
		else
		{
			minEnding = 1;
			maxEnding = 1;
		}

		bestSubarrayProduct = max(maxEnding, bestSubarrayProduct);
	}

	return bestSubarrayProduct;
}

int main()
{
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int bestSubarrayProduct = bestProduct(arr, n);

	cout << bestSubarrayProduct << endl;

	delete [] arr;

	return 0;
}