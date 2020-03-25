// Largest Piece

// Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
// Constraints :
// 1<=N<=50
// Input Format :

// Line 1 : An integer N denoting the size of cake 
// Next N lines : N characters denoting the cake

// Output Format :

// Size of the biggest piece of '1's and no '0's

// Sample Input :

// 2
// 11
// 01

// Sample Output :

// 3

#include<bits/stdc++.h>
using namespace std;
#define NMAX 55

char cake[NMAX][NMAX];

int getLargestPiece(char cake[][NMAX], int n, int row, int col, bool **visited) {

	if(row >= n || col >= n || row < 0 || col < 0) {
		return 0;
	}
	if(cake[row][col] != '1' || visited[row][col]) {
		return 0;
	}

	visited[row][col] = true;

	int option1 = getLargestPiece(cake, n, row, col+1, visited);
	int option2 = getLargestPiece(cake, n, row, col-1, visited);
	int option3 = getLargestPiece(cake, n, row+1, col, visited);
	int option4 = getLargestPiece(cake, n, row-1, col, visited);

	int ans = 1 + option1 + option2 + option3 + option4;

	return ans;
}


int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
	bool **visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[n];
		for(int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	int ans = INT_MIN;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(cake[i][j] == '1') {
				ans = max(getLargestPiece(cake, n, i, j, visited), ans);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		delete [] visited[i];
	}
	delete [] visited;

	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}