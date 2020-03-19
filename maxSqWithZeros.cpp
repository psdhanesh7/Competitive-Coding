#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */

	int **dp = new int*[row];
	for(int i = 0; i < row; i++)
	{
		dp[i] = new int[col];
	}

	for(int i = 0; i < row; i++)
	{
		dp[i][0] = arr[i][0] == 1 ? 0 : 1;
	}

	for(int i = 0; i < col; i++)
	{
		dp[0][i] = arr[0][i] == 1 ? 0 : 1;
	}

	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(arr[i][j] == 0)
			{
				dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
			}
			else
			{
				dp[i][j] = 0;
			}
			
		}
	}

	int maximum = 0;
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			maximum = max(maximum, dp[i][j]);
		}
	}
    for(int i = 0; i < row; i++)
    {
    	// for(int j = 0; j < col; j++)
    	// {
    	// 	cout << dp[i][j] << " ";
    	// }
    	// cout << endl;
        delete [] dp[i];
    }
    
    delete [] dp;
    return maximum;
}



int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}