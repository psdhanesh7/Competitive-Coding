#include <bits/stdc++.h>
using namespace std;

long m = 10e9+7;

long getNoOfDecodings(int *n, int size, int *dp)
{
	if(size == 0 || size == 1)
	{
		return 1;
	}

	if(dp[size] != -1)
	{
		return dp[size];
	}


	long output = 0;
	if(n[size-1] != 0)
	{
		output = getNoOfDecodings(n, size-1, dp);
	} 
	

	if(n[size-2] * 10 + n[size-1] <= 26 && n[size-2] != 0)
	{
		output = (output + getNoOfDecodings(n, size-2, dp)) % m;
	}

	dp[size] = output;
	return output;
}

int main()
{    
    string code;
    cin >> code;
    
    do
    {
    	int *n = new int[code.length()];
    	for(int i = 0; i < code.length(); i++)
    	{
    		n[i] = code[i] - '0';
    	}

    	int *dp = new int[code.length()+1];
    	for(int i = 0; i <= code.length(); i++)
    	{
    		dp[i] = -1;
    	}

    	long ans = getNoOfDecodings(n, code.length(), dp);	

        cout << ans << endl;

        delete [] n;
        delete [] dp;
              
        cin >> code;

    }while(code[0] != '0');
    
    return 0;
}
