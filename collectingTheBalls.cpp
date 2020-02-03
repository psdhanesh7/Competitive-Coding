#include<bits/stdc++.h>
using namespace std;

long long sharmasShare(long long n, long long k)
{
	long long remainingCandies = n;
	long long sharmasCandies;
	long long count = 0;

	while(remainingCandies > k)
	{
		remainingCandies = remainingCandies - k;
		remainingCandies = remainingCandies - (remainingCandies/10);
		count++;
	}

	sharmasCandies = k * count + remainingCandies;
	return sharmasCandies;
}

int main()
{
	long long n;
	cin >> n;

	long long maximum = n;
	long long minimum = 1;
	long long k = 1;
	long long ans;

	while(minimum <= maximum)
	{
		k = (minimum + maximum)/2;

		long long sharmasCandies = sharmasShare(n, k);

		if((sharmasCandies >= n/2 && n%2 == 0) || (sharmasCandies > n/2 && n%2 != 0))
		{
			ans = k;
			maximum = k-1;
		}
		else
		{
			minimum = k+1;
		}

	}

	cout << ans << endl;
	return 0;
}