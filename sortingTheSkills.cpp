#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *skills, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		if(skills[i] > skills[i+1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		int *skills = new int[n];
		for(int i = 0; i < n; i++)
		{
			cin >> skills[i];
		}

		for(int i = 0; i < n-1; i++)
		{
			if(skills[i+1] == skills[i]-1)
			{
				int temp = skills[i];
				skills[i] = skills[i+1];
				skills[i+1] = temp;
			}
		}

		bool sorted = isSorted(skills,n);
		if(sorted)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		delete [] skills;
	}

	return 0;
}