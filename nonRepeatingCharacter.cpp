//Frist non repeating charecter

//In a given string, find the first non-repeating charecter.You are given a string, that can contain repeating charecters.Your task is to return the first charecter in the string that does not repeat,
// ie, occurs exactly once.The string will contain charecters only from English alphabet set, (A - Z) and (a - z).If there is no non repeating charecter print the first charecter of the string

#include<bits/stdc++.h>

using namespace std;

char nonRepeatingCharecter(string input)
{
	map<char, int> frequency;

	char currentCharecter;
	int length = input.length();

	for(int i = 0; i < length; i++)
	{
		currentCharecter = input[i];
		
		frequency[currentCharecter] = frequency[currentCharecter] + 1;
	}

	for(int i = 0; i < length; i++)
	{
		currentCharecter = input[i];

		if(frequency[currentCharecter] == 1)
			return currentCharecter;
	}

	return input[0];
}