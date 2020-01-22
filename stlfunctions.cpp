#include<bits/stdc++.h>

using namespace std;

struct interval{

	int startTime, endTime;
};

bool compare(interval i1, interval i2) 
{										//the funtions returns true when the following condition holds
	return i1.startTime < i2.startTime; //The one which is smaller comes first
										//This function will tell to sort the interval in the ascending oreder of startTime
}  

int main(int argc, char const *argv[])
{

	//Sort function

	//to use the sort algorithm we need to include the <algorithm> library
	//in this function we need to give the begin pointer as well as the end pointer
	//suppose we have an array arr with 6 elemnts

	int arr[] = {2, 1, 5, 3, 6, 7};

	sort(arr+2, arr+6);
	//here the complete array will be sorted
	//note that end pointer is arr+6, ie, the end pointer is the pointer which points to the theoratical element after the last element

	for( int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl ;

	//if I give the begin pointer as arr+2 instead of giving arr, then the array the output would be the folloing

	//2 1 3  5 6 7
	
	//ie , array will be sorted from index 2 onwards

	//Now if I want to sort the array in descending order, i need to use the function greater<int>() as the third argument of the sort fuction

	sort(arr, arr+6, greater<int>());

	for( int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl ;

	//Suppose my sorting criteria is something else
	// Example , we are given an list of intervals and need to sort these intervals based on their starting time or ending time.In that case also we can use the sort function
	//but in this case we will have to make our own compare function

	interval ar[] = {{6, 4}, {3, 4}, {4, 6}, {8, 13}};

	sort(ar, ar+4, compare);
	//Note that there is no pranthesis after the compare funtion

	for(int i = 0; i < 4; i++)
	{
		cout << ar[i].startTime << " : " << ar[i].endTime << endl;
	}
	cout << endl;

	//Binary search

	sort(arr, arr+6);

	//arr[] = {1, 2, 3, 5, 6, 7}

	//to perform binary search , array needs to be sorted
	//the function used is binary_search()
	//syntax is binary_search(startIndex, endIndex, value)

	cout << binary_search(arr, arr+6, 2) << endl;

	//the funtion returns 1 or 0 depending on the condition
	//for this function to work array should be sorted in ascending order

	//binry_search funtion returns only whether the element is present in the array array or not. We cannot know the index
	//if we want the index of the given value, then we need to use the function lower_bound()
	//syntax is lower_bound(startinIndex, endIndex, value);
	//lower_bound() actually returns the pointer to the variable
	//what we need is the index
	//to get the index we can do the following

	cout << "Your array is : " << endl;

	for(int i = 0; i < 6; i++)
		cout << arr[i] << " " ;
	cout << endl;

	cout << "Lower bound of 2 : " << lower_bound(arr, arr+6, 2) - arr << endl;

	//if the given element is not found, then it returns a pointer to the next higher element in the array

	cout << "Lower bound of 4 : " << lower_bound(arr, arr+6, 4) - arr << endl;

	//the output will be 3 which is the index of 5

	//if there are repeated values, then the lower_bound() returnd the index of the first occurence

	//There is one more functionality called upper_bound()

	//if the element is found, upper_bound  returns the index of the next higher element 

	cout << "Upper bound of 3 : " << upper_bound(arr, arr+6, 3) - arr << endl;

	//if there are repeated elements then it returns the index to the next element after the final occurence

	//We also have a gcd function in algorithm library
	//function name is __gcd();

	cout << gcd(10, 6) << endl;

	//we also have a swap function
	//swap function is available in <utility> library

	int x = 10, y = 12;

	swap(x,y);

	cout << x << " " << y << endl;

	return 0;
}