// Connecting Dots

// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
// Assume input to be 0-indexed based.
// Input Format :

// Line 1 : Two integers N and M, the number of rows and columns of the board
// Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.

// Output Format :

// Return 1 if there is a cycle else return 0

// Constraints :
// 2 ≤ N, M ≤ 50
// Sample Input :

// 3 4
// AAAA
// ABCA
// AAAA

// Sample Output :

// 1


#include<bits/stdc++.h>
using namespace std;
#define MAXN 51

void deleteVisited(bool **visited, int n) {

	for(int i = 0; i < n; i++) {
		delete [] visited[i];
	}
	delete [] visited;
}
bool cyclePresent(char board[][MAXN], int n, int m, int row, int col, int startRow, int startCol, int depth, char prevChar, bool **visited) {

	if(row >= n || col >= m || row < 0 || col < 0) {
		return false;
	}
	if(row == startRow && col == startCol && depth >= 4) {
		return true;
	}
	if(visited[row][col]) {
		return false;
	}
	if(board[row][col] != prevChar) {
		return false;
	}

	visited[row][col] = true;
	if(cyclePresent(board, n, m, row, col+1, startRow, startCol, depth+1, prevChar, visited) || cyclePresent(board, n, m, row, col-1, startRow, startCol, depth+1, prevChar, visited) || cyclePresent(board, n, m, row+1, col, startRow, startCol, depth+1, prevChar, visited) || cyclePresent(board, n, m, row-1, col, startRow, startCol, depth+1, prevChar, visited)){
		return true;
	}

	visited[row][col] = false;

	return false;
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
	bool **visited = new bool*[n];
	for(int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		for(int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {

			if(cyclePresent(board, n, m, i, j, i, j, 0, board[i][j], visited)) {
				deleteVisited(visited, n);
				return 1;
			}
		}
	}

	deleteVisited(visited, n);
	return 0;
}


int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}