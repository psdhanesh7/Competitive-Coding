//write a recursive function to check if an array is sorted or not

#include<bits/stdc++.h>

using namespace std;

bool isSorted(int ar[], int size)
{
	if( size == 0 || size == 1) //base condition
		return true;

	int smallerOutput = isSorted(ar+1, size-1);	//checks if the smaller array is sorted or not 

	if(!smallerOutput) //if smaller array is not sorted, then we know that this array is also not sorted  
		return false;

	if(ar[0] < ar[1]) // if the smaller array is sorted, we check if the first element of this array is less than the first element of the sorted array
		return true;	//if that is the case, then our array is also sorted
	else
		return false;  //else array is not sorted
}

int main(int argc, char const *argv[])
{
	int ar[] = {1, 2, 3, 4, 5};

	bool sorted = isSorted(ar, 5);

	cout << (sorted ? "Sorted" : "Not sorted") << endl;

	return 0;
}