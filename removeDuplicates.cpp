//Given an integer array A which contain duplicates.Remove duplicates from the array and return a new array without any duplicates

//That is, it should comtain only  unique elements
//Note best case time-complexity is O(n), where n is the number of elements in the array

//Input format 
//Line 1 : contains the size of the array
//Line 2 : N space separated integers which are elemnts of the array

//Solution 

#include<bits/stdc++.h>

using namespace std;

vector<int> removeDuplicates(vector<int> input)
{
	set<int> s;
	std::vector<int> result;

	for(int i = 0; i < input.size(); i++)
	{												//Time-complexity and space complexity of this solution is O(n);
		if(s.find(input[i]) == s.end())
		{
			s.insert(input[i]);
			result.push_back(input[i]);
		}

	}

	return result;
}

//Another way to do this problem is to sort the input array so that all the repeating charecters occur together

vector<int> removeDuplicates(vector<int> input)
{
	std::vector<int> result;

	sort(input.begin(), input.end());

	result.push_back(input[0]);

	for(int i = 1; i < input.size(); i++)
	{
		if(input[i] != input[i-1])
			result.push_back(input[i]);
	}

	return result;

}