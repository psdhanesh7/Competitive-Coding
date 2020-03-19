#include<bits/stdc++.h>
using namespace std;

int findCost(int ar[], int n, int mean, int k, int l)
{
	int pos = 0, neg = 0;
	int diff[1001];
	for(int i = 0; i < n; i++)
	{
		diff[i] = mean-ar[i];
		diff[i] >= 0 ? pos += diff[i] : neg += diff[i];
	}

	int ans = INT_MAX;
	if(pos + neg > 0)
		ans = (-neg * k) + (pos + neg) * l;

	return ans;
}

int main()
{
	int n, k, l;
	cin >> n >> k >> l;

	int ar[1001];
	int minimum = INT_MAX;
	int maximum = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		cin >> ar[i];
		maximum = max(ar[i], maximum);
		minimum = min(ar[i], minimum);
	}

	int minCost = INT_MAX;
	int cost;
	for(int i = minimum; i <= maximum; i++)
	{
		cost = findCost(ar, n, i, k, l);
		minCost = min(cost, minCost);
	}

	cout <<  minCost << endl;
	return 0;
}