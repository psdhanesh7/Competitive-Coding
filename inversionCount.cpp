// Inversion Count

// Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
// Input format :

// Line 1 : n, array size
// Line 2 : Array elements (separated by space).

// Output format :

// Count of inversions

// Constraints :
// 1 <= n <= 10^5
// 1 <= A[i] <= 10^9
// Sample Input 1 :

// 3
// 3 2 1

// Sample Output 1 :

// 3

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long merge(int A[],int start, int mid , int end)
{
    int arr[end - start + 1];
    int  i = start, j = mid, k = 0;
    long long count = 0;
    
    while(i < mid && j <= end)
    {
        if(A[i] <= A[j])
        {
            arr[k++] = A[i++];
        }
        else
        {
            arr[k++] = A[j++];
            count += (mid - i);
        }
    }
    
    while(i < mid)
    {
        arr[k++] = A[i++];
    }
    
    while(j <= end)
    {
        arr[k++] = A[j++];
    }
    
	for(int i = start, k = 0; i <= end; i++, k++)
	{
        A[i] = arr[k];
    }
    
    return count;
}

long long mergeSort(int a[], int start, int end)
{
    if(end > start)
    {
        int mid = (start + end)/2;
        
        long long leftAns = mergeSort(a, start, mid);
        long long rightAns = mergeSort(a, mid+1, end);
        
        long long currentAns = merge(a, start, mid+1, end);
        
        long long ans = leftAns + rightAns + currentAns;
        return ans;
    }
    return 0;
}


long long solve(int A[], int n)
{
	// Write your code here.
    long long ans = mergeSort(A, 0, n-1);
    return ans;
}


int main()
{
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}
