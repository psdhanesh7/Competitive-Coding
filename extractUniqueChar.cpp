// Extract Unique characters

// Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.

// Input format :
// String S

// Output format :
// Output String

// Constraints :
// 1 <= Length of S <= 50000

// Sample Input 1 :
// ababacd



#include<iostream>
#include<map>
using namespace std;


char* uniqueChar(char *str){
    // Write your code here
    
    unordered_map<char, bool> visited;
    queue<char> q;
    
    int i;
    
    for(i = 0; str[i] != 0; i++)
    {
        if(!visited[str[i]])
        {
            visited[str[i]] = true;
            q.push(str[i]);
        }
    }
    
    char* newString = new char[i];    
    i = 0;
    while(!q.empty())
    {
        newString[i] = q.front();
        q.pop();
        i++;
    }
    
    return newString;
}


int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
