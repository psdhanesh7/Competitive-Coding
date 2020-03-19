#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	int prev = -1;
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(prev != -1 && i-prev >= 2)
		{
			count++;
			prev = -1;
		}

		if(prev != -1 && a[i] != b[i] && a[i] != a[prev])
		{
			int temp = a[i];
			a[i] = a[prev];
			a[prev] = temp;

			count++;
			prev = -1;
		}
		else if(prev != -1 && a[i] != b[i])
		{
			continue;
		}
		else if(a[i] != b[i])
		{
			prev = i;
		}
	}

	if(prev != -1)
	{
		count++;
	}

	cout << count << endl;
	return 0;
}