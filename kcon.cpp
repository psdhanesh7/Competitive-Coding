#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadanes(int *arr, int n)
{
	ll bestSum = INT_MIN;
	ll currentSum = 0;

	for(int i = 0; i < n; i++)
	{
		currentSum += arr[i];
		bestSum = max(bestSum, currentSum);

		if(currentSum < 0)
		{
			currentSum = 0;
		}
	}

	return bestSum;

}

ll maxSubArraySum(int *arr, int n, int k)
{
	ll kadanesSum = kadanes(arr, n);
	if(k == 1){
		return kadanesSum;
	}

	ll bestPrefixSum = INT_MIN, bestSufixSum = INT_MIN;
	ll currentPrefixSum = 0, currentSufixSum = 0;

	for(int i = 0; i < n; i++)
	{
		currentPrefixSum += arr[i];
		bestPrefixSum = max(currentPrefixSum, bestPrefixSum);
	}

	ll totalSum = currentPrefixSum;

	for(int i = n-1; i >= 0; i--)
	{
		currentSufixSum += arr[i];
		bestSufixSum = max(currentSufixSum, bestSufixSum);
	}

	ll ans;

	if(totalSum < 0){
		ans = max(bestPrefixSum + bestSufixSum, kadanesSum);
	}
	else{
		ans = max((k-2)*totalSum + bestSufixSum + bestPrefixSum, kadanesSum);
	}

	return ans;
}

// ll bestPrefixSum(int *arr, int n)
// {
// 	ll bps = 0;
// 	ll sum = 0;
// 	for(int i = 0; i < n; i++)
// 	{
// 		sum += arr[i];
// 		bps = max(bps, sum);
// 	}

// 	return bps;
// }

// int bestSufixSum(int *arr, int n)
// {
// 	ll bss = 0;
// 	ll sum = 0;

// 	for(int i = n-1; i >= 0; i--)
// 	{
// 		sum += arr[i];
// 		bss = max(sum, bss);
// 	}

// 	return bss;
// }

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int *arr = new int[n];

		// int arrSum = 0;
		// ll sum;

		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// arrSum += arr[i];
		}

		// ll bps = bestPrefixSum(arr, n);
		// ll bss = bestSufixSum(arr, n);
		// ll kadanes = kadanesSum(arr, n);

		// if(k == 1){
		// 	sum = kadanes;
		// }
		// else if(arrSum >= 0){
		// 	sum = max((k-2)*arrSum+bps+bss, kadanes);
		// }
		// else{
		// 	sum = max(bps+bss, kadanes);
		// }

		ll totalSum = maxSubArraySum(arr, n, k);

		cout << totalSum << endl;

		delete [] arr;
	}
}