#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n, x, y;
    cin >> n >> x >> y;
    
    string bulbs;
    cin >> bulbs;
    
    int zeroGroups = 0;

    for(int i = 1; i < n; i++)
    {
    	if(bulbs[i-1] == '0' && bulbs[i] == '1')
    	{
    		zeroGroups++;
    	}
    }

    if(bulbs[n-1] == '0')
    {
    	zeroGroups++;
    }
    long ans;
    
    if(zeroGroups == 0)
    {
        ans = 0;
    }
    else
    {
        ans = (zeroGroups-1) * min(x, y) + y;
    }
    cout << ans << endl;

	return 0;
}
