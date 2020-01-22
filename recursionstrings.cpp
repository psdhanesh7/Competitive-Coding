#include<bits/stdc++.h>

using namespace std;

//function to find the length of a string using recursion 

int findLength(char s[])
{
	if(s[0] == '\0')
		return 0;

	int ans = findLength(s+1);

	return ans + 1;
}

//consider you are given a string of characters, where charecters are only english alphabets
//you need to remove all the  'x' from the given string using recursion

void removeX(char s[])
{
	if(s[0] == '\0')
		return ;

	if(s[0] != 'x')
		removeX(s+1);   //if the first charecter is not x, then we just need to remove all the 'x' from the substring with one character less than that
	else
	{
		//if the first character is 'x', then we need to shift all the charaters after it to left by one position and remove 'x' from that
		int i;

		for(i = 1; s[i] != '\0'; i++)
			s[i-1] = s[i];

		s[i-1] = s[i]; //to copy the NULL character

		//now we have to perform the removeX() operation on this string 

		removeX(s);
	}
}

int main(int argc, char const *argv[])
{
	char str[100];

	cin >> str ;

	cout << "Length of the entered string is : " << findLength(str) << endl;

	removeX(str);

	cout << str << endl;

	return 0;
}