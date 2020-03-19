#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

void deleteVisited(bool **visited, int n, int m)
{
	for(int i = 0; i < n; i++){
		delete [] visited[i];
	}

	delete [] visited;
}

bool isPathAvailable(char Graph[][MAXN], int n, int m, int row, int col, string word, int index, bool **visited)
{
	if(index == word.length())
	{
		return true;
	}

	if(row < 0 || row >= n || col < 0 || col >= m)
	{
		return false;
	}

	if(Graph[row][col] != word[index])
	{
		return false;
	}

	visited[row][col] = true;

	if(isPathAvailable(Graph, n, m, row, col+1, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row, col-1, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row-1, col, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row+1, col, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row-1, col+1, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row-1, col-1, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row+1, col+1, word, index+1, visited)){
		return true;
	}
	else if(isPathAvailable(Graph, n, m, row+1, col-1, word, index+1, visited)){
		return true;
	}

	visited[row][col] = false;

	return false;

}

int solve(char Graph[][MAXN],int n, int m)
{
	// Write your code here.
	bool **visited = new bool*[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for(int j = 0; j < m; j++){
			visited[i][j] = false;
		}
	}

	string word = "CODINGNINJA";

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(Graph[i][j] == 'C')
			{
				visited[i][j] = true;
				if(isPathAvailable(Graph, n, m, i, j+1, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i, j-1, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i-1, j, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i+1, j, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i-1, j+1, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i-1, j-1, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i+1, j+1, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				else if(isPathAvailable(Graph, n, m, i+1, j-1, word, 1, visited)){
					deleteVisited(visited, n, m);
					return 1;
				}
				visited[i][j] = false;
			}
		}
	}
	deleteVisited(visited, n, m);
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