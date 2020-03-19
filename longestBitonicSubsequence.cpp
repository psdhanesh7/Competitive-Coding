	
int longestBitonicSubarray(int *input, int n) {
	
/* Don't write main().
 	* the input is already passed as function argument.
 	* Taking input and printing output is handled automatically.
 	*/
    
   	int *increasing = new int[n];
   	int *decreasing = new int[n];

   	for(int i = 0; i < n; i++)
   	{
   		increasing[i] = 1;
   		for(int j = 0; j < i; j++)
   		{
   			if(input[i] > input[j])
   			{
   				increasing[i] = max(increasing[i], 1+increasing[j]);
   			}
   		}
   	}

   	for(int i = n-1; i > 0; i--)
   	{
   		decreasing[i] = 1;
   		for(int j = n-1; j > i; j--)
   		{
   			if(input[i] > input[j])
   			{
   				decreasing[i] = max(decreasing[i], 1+decreasing[j]);
   			}
   			
   		}
   	}

   	int maxLength = 0;
   	for(int i = 0; i < n; i++)
   	{
        // cout << i << " : " << increasing[i] << " " << decreasing[i] << endl;
   		maxLength = max(maxLength, increasing[i] + decreasing[i]);
   	}
    
    delete [] increasing;
    delete [] decreasing;
 	
 	return maxLength-1;
 	
}

