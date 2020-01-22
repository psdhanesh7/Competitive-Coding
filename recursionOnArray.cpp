#include<bits/stdc++.h>

using namespace std;

//Sum of Array

// Given an array of length N, you need to find and return the sum of all elements of the array.
// Do this recursively.

// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces

int sum(int input[], int n) {
  
    if(n == 1)
        return input[0];
    
    int smallAnswer = sum(input+1, n-1);
    int ans = input[0] + smallAnswer;
    
    return ans;

}


// Check Number

// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
// Do this recursively.
// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

bool checkNumber(int input[], int size, int x) {
 
    if(size == 0)
        return false;
    
    if(input[0] == x)
        return true;
    
    bool ans = checkNumber(input+1, size-1, x);
    
    return ans;
}


// First Index of Number

// Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
// First index means, the index of first occurrence of x in the input array.
// Do this recursively. Indexing in the array starts from 0.
// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

int firstIndex(int input[], int size, int x) {
 
    if(size == 0)
        return -1;
    if(input[0] == x)
        return 0;
    
    int index = firstIndex(input+1, size-1, x);
    if(index != -1)
        return index + 1;
    else
        return index;
}

// Last Index of Number

// Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
// Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
// You should start traversing your array from 0, not from (N - 1).
// Do this recursively. Indexing in the array starts from 0.
// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

int lastIndex(int input[], int size, int x) {

    if(size == 0)
        return -1;
    
    if(input[size-1] == x)
        return size-1;
    
    int ans = lastIndex(input, size-1, x);
    
    return ans;
}

// All Indices of Number

// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
// Do this recursively. Indexing in the array starts from 0.
// Input Format :

// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

// Output Format :

// indexes where x is present in the array (separated by space)


int allIndexes(int input[], int size, int x, int output[]) {
    
    if(size == 0)
        return 0;
    
    int ans = allIndexes(input, size-1, x, output);
    
    if(input[size-1] == x)
    {
        output[ans] = size-1;
        return ans + 1;
    }
    else
        return ans;
        
00}



