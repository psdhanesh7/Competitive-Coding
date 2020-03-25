// Coding Ninjas

// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
// There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
// Input Format :

// Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
// Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on

// Assume input to be 0-indexed based
// Output Format :

// Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.

// Constraints :
// 1 <= N <= 100
// 1 <= M <= 100
// Sample Input :

// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX

// Sample Output :

// 1


#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

void deleteVisited(bool **visited, int N) {
	for(int i = 0; i < N; i++) {
		delete [] visited[i];
	}
	delete [] visited;
}

bool findPath(char graph[][MAXN], int n, int m, int i, int j, bool **visited, string path) {

	if(path == ""){
		return true;
	}
	if(i >= n || j >= m || i < 0 || j < 0) {
		return false;
	}
	if(visited[i][j] || graph[i][j] != path[0]) {
		return false;
	}

	visited[i][j] = true;
	if(findPath(graph, n, m, i, j+1, visited, path.substr(1)) || findPath(graph, n, m, i, j-1, visited, path.substr(1)) || findPath(graph, n, m, i+1, j, visited, path.substr(1)) || findPath(graph, n, m, i-1, j, visited, path.substr(1))){
		visited[i][j] = false;
		return true;
	}
	else if(findPath(graph, n, m, i+1, j+1, visited, path.substr(1)) || findPath(graph, n, m, i+1, j-1, visited, path.substr(1)) || findPath(graph, n, m, i-1, j+1, visited, path.substr(1)) || findPath(graph, n, m, i-1, j-1, visited, path.substr(1))) {
		visited[i][j] = false;
		return true;
	}
	visited[i][j] = false;

	return false;
}

int solve(char Graph[][MAXN],int N, int M)
{
	bool **visited = new bool*[N];
	for(int i = 0; i < N; i++) {

		visited[i] = new bool[M];
		for(int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	string path = "CODINGNINJA";

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(Graph[i][j] == 'C') {
				if(findPath(Graph, N, M, i, j, visited, path)) {
					deleteVisited(visited, N);
					return 1;
				}
			}
		}
	}

	deleteVisited(visited, N);
    return 0;
}

int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}