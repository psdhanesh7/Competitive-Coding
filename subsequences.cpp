//The question is to return  all the subsequences of a given string

#include<bits/stdc++.h>

using namespace std;

int subsequences(string input, string *output)
{
	if(input.empty())
	{
		output[0] = "";
		return 1;
	}

	int smallerAnsSize = subsequences(input.substr(1), output); //finding all the subsequeces of the substring starting from first index

	for(int i = 0; i < smallerAnsSize; i++)
	{
		output[i+smallerAnsSize] = input[0] + output[i]; //appending the first charecter to all the subsequences we already know
	}

	smallerAnsSize = 2 * smallerAnsSize;

	return smallerAnsSize;
}

int main(int argc, char const *argv[])
{
	string input;

	cin >> input;

	string *output = new string[1000];

	int length = subsequences(input, output);

	for(int i = 0; i < length; i++)
	{
		cout << output[i] << endl ;
	}

	delete [] output;
	return 0;
}