// Free from cubes
// Level MEDIUM
// A cube free number is a number whose none of the divisor is a cube number.
// A cube number is a cube of an integer like 8 (2^3) , 27 (3^3).
// So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc. We will consider 1 as cube free. 8, 16, 24, 27, 32 etc are not cube free numbers. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9.
// Given a positive number, you have to say if its a cube free number. If yes then tell its position among cube free numbers and if not you have to print "Not Cube Free".
// Input Format :

// Line 1 : An integer.

// Output Format :

// Line 1 : Either the position of number or the String "Not Cube Free"

// Sample Input 1:

// 100

// Sample Output :

// 85

// Sample Input :

// 8

// Sample Output :

// Not Cube Free




#include<bits/stdc++.h>
using namespace std;

#define MAX 100000000

int cubeFreeNo[MAX];

void sieve(int n) {
    
    for(int i = 0; i <= n; i++) {
		cubeFreeNo[i] = i;
    }
    
    for(int i = 2; i*i*i <= n; i++) {
        if(cubeFreeNo[i] == i) {
           	int cube = i*i*i;
            for(int j = 1; j*cube <= n; j++) {
                cubeFreeNo[j*cube] = 0;
            }
        }
    }
    
    for(int i = 2; i <= n; i++) {
        if(cubeFreeNo[i] == i) {
            cubeFreeNo[i] = cubeFreeNo[i-1] + 1;
        }
        else {
            cubeFreeNo[i] = cubeFreeNo[i-1];
        }
    }
}

void cubeFree(int num)
{
	// Write your code here
    sieve(num);

    if(cubeFreeNo[num-1] == cubeFreeNo[num]) {
    	cout << "Not Cube Free" << endl;
    }
    else {
		cout << cubeFreeNo[num] << endl;
	}    
}

int main() {

	int num;
	cin >> num;

	cubeFree(num);

	return 0;
}