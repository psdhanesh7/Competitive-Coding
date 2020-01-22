// Rotate array

// Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
// Change in the input array itself. You don't need to return or print elements.

// Input format :

// Line 1 : Integer n (Array Size)
// Line 2 : Array elements (separated by space)
// Line 3 : Integer d

// Output Format :
// Updated array elements (separated by space)

// Constraints :
// 1 <= N <= 1000
// 1 <= d <= N

// Sample Input :

// 7
// 1 2 3 4 5 6 7
// 2

// Sample Output :

// 3 4 5 6 7 1 2

#include <bits/stdc++.h>
using namespace std;

// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int currentIndex = 0;
    int newIndex = (currentIndex + size - d)%size;
    
    while(newIndex != 0)
    {
        int temp = arr[0];
        arr[0] = arr[newIndex];
        arr[newIndex] = temp;
        
        currentIndex = newIndex;
        newIndex = (currentIndex + sizea - d)%size;
    }

}	


int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	delete [] input;
	return 0;

}
