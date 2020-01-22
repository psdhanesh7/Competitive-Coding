#include<bits/stdc++.h>
using namespace std;
// int nod(int n)
// {
// 	int count;
// 	while(n)
// 	{
// 		count++;
// 		n/=10;
// 	}
// 	return count;
// }

long long int superdigit(int n)
{
	if(n==0)
		return 0;
	long long int ans=n%10+superdigit(n/10);
	while(ans>9)
		ans=ans%10+superdigit(ans/10);
	return ans;
}

int main()
{
	long long int n,k;
	cin>>n>>k;
	long long int ans=superdigit(n);
	ans=ans*k;
	ans=superdigit(ans);
	cout<<ans<<endl;
	return 0;
}