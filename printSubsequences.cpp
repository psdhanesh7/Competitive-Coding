//In the previous question about subsequences we were storing all the subsequences which takes a lot of space 
//If we just need to print all the subsequences rather than returning them, then we are returning a lot of memory
//this program shows how to print all the subsequences of a string

#include<bits/stdc++.h>

using namespace std;

void printSubsequences(string input, string output)
{
	if(input.length() == 0)
	{
		cout << output << endl;
		return;
	}

	//here we are making two decisions

	printSubsequences(input.substr(1), output); //first one is that our output does not contain the first character of the input 

	printSubsequences(input.substr(1), output + input[0]);  //second one is that our input contain the first character of the input
}

int main(int argc, char const *argv[])
{
	/* code */
	string input, output = "";

	cin >> input ;

	printSubsequences(input, output);

	return 0;
}