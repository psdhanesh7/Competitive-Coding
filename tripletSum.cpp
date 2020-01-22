// Triplet sum

// Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
// While printing a triplet, print the smallest element first.
// That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which have to be printed on 1st line. You can print triplets in any order, just be careful about the order of elements in a triplet.

// Input format :

// Line 1 : Integer N (Array Size)
// Line 2 : Array elements (separated by space)
// Line 3 : Integer x

// Output format :

// Line 1 : Triplet 1 elements (separated by space)
// Line 2 : Triplet 3 elements (separated by space)
// Line 3 : and so on

// Constraints :
// 1 <= N <= 1000
// 1 <= x <= 100
// Sample Input:

// 7
// 1 2 3 4 5 6 7 
// 12

// Sample Output ;

// 1 4 7
// 1 5 6
// 2 3 7
// 2 4 6
// 3 4 5

#include <bits/stdc++.h>
using namespace std;

// void FindTriplet(int arr[], int size, int x) 
// {
// 	sort(arr, arr+size);
// 	for(int i = 0; i < size; i++)
// 	{
// 		int dupletSum = x - arr[i];
// 		int start = i+1;
// 		int end = size-1;

// 		while(start < end)
// 		{
// 			int currentSum = arr[start] + arr[end];
// 			if(currentSum == dupletSum){
// 				cout << arr[i] << " " << arr[start] << " " << arr[end] << endl;
// 				start++;
// 				end--;
// 			}
// 			else if(currentSum < dupletSum){
// 				start++;
// 			}
// 			else if(currentSum > dupletSum){
// 				end--;
// 			}
// 		}
// 	}
// }

// arr - input array
// size - size of array
// x - sum of triplets


// void tripletSumHelper(int arr[], int start, int end, int dupletSum)
// {
//     int firstIndex = start-1;
//     while(start < end)
// 		{
// 			int currentSum = arr[start] + arr[end];
// 			if(currentSum == dupletSum){
// 				cout << arr[firstIndex] << " " << arr[start] << " " << arr[end] << endl;
// 				start++;
// 				end--;
// 			}
// 			else if(currentSum < dupletSum){
// 				start++;
// 			}
// 			else if(currentSum > dupletSum){
// 				end--;
// 			}
// 		}
// }


// void FindTriplet(int arr[], int size, int x) {
//     /* Don't write main().
//      * Don't read input, it is passed as function argument.
//      * Print output and don't return it.
//      * Taking input is handled automatically.
//      */
    
//     sort(arr, arr+size);
    
//     map<int, int> frequency;

//     for(int i = 0; i < size; i++){
//         frequency[arr[i]]++;
//     }

//     // for(int i = 0; i < size; i++)
//     // {
//     // 	cout << frequency[arr[i]] << " " ;
//     // }
    
//     for(int i = 0; i < size; i++)
//     {
//         int start = i+1;
//         int end = size - 1;
//         int dupletSum = x - arr[i];

//         // cout << "i = " << i << endl;
        
//         while(start < end)
//         {

//             int currentSum = arr[start] + arr[end];
//             int startFrequency, endFrequency;

//             if( i == 0){
//                 startFrequency = frequency[arr[start]];
//             	endFrequency = frequency[arr[end]];            	
//             }
//             else if(arr[start] != arr[start - 1])
//             {
//                 startFrequency = frequency[arr[start]];
//             	endFrequency = frequency[arr[end]];
//             }

//          //    cout << "start = " << start << " " << "end = " <<  end << endl;
//         	// cout << "currentSum = " << currentSum << " " << "dupletSum = " << dupletSum << endl;
//             if(currentSum == dupletSum){
                
//                 int freq = startFrequency * endFrequency;

//                 // cout << frequency[arr[end]] << " " << frequency[arr[start]] << endl;
//                 // cout << "*" << endl;
//                 for(int j = 0; j < freq; j++){
//                     cout << arr[i] << " " << arr[start] << " " << arr[end] << endl;
//                     continue;
//                 }
                
//                 startFrequency = 0;
//                 start++;
//                 // cout << frequency[arr[start]] << " " << frequency[arr[end]] << endl;
//             }
//             else if(currentSum < dupletSum){
//                 start++;
//             }
//             else{
//                 end--;
//             }
//         }
//     }
    
    

// }

void FindTriplet(int arr[], int size, int x)
{
	unordered_map<int, int> frequency;
	for(int i = 0; i < size; i++){
		frequency[arr[i]]++;
	}

	sort(arr, arr+size);

	for(int i = 0; i < size; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			int dupletSum = arr[i] + arr[j];
			for(int k = 0; k < frequency[x-dupletSum]; k++){
				if(x-dupletSum <= arr[i]){
					cout << x-dupletSum << " " << arr[i] << " " << arr[j] << endl;
				}
				else if(x-dupletSum <= arr[j]){
					cout << arr[i] << " " << x-dupletSum << " " << arr[j] << endl;
				}
				else{
					cout << arr[i] << " " <<  arr[j] << " " << x-dupletSum << endl; 
				}
			}
		}
	}
}

int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);

	delete [] input;
		
	return 0;
}



