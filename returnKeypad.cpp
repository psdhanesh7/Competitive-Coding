// Return Keypad Code

// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : The order of strings are not important.
// Input Format :

// Integer n

// Output Format :

// All possible strings in different lines

#include<bit/stdc++.h>

using namespace std;

string options(int n)
{
	switch(n)
	{
		case 2 : return "abc";

		case 3 : return "def";

		case 4 : return "ghi";

		case 5 : return "jkl";

		case 6 : return "mno";

		case 7 : return "pqrs";

		case 8 : return "tuv";

		case 9 : return "wxyz";

		default : return "";
	}
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(num == 0)
    {
        output[0] = "";
        return 1;
    }
    
    int smallerNum = num / 10;
    int digit  = num % 10;
    
    string smallerOutput[500];
    
    int smallerAnsSize = keypad(smallerNum, smallerOutput);
    
    
    string op = options(digit);
    
    int length = op.length();
    
    int k = 0;
     // Python (3.5) 
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < smallerAnsSize; j++)
        {
            output[k++] = smallerOutput[j] + op[i];
        }
    
    }
    return k;
        
}
