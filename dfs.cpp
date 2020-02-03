#include<iostream>
using namespace std;

void printDFS(int **edges, int v, int sv, bool *visited)
{
	cout << sv << " " ;
	visited[sv] = true;

	for(int i = 0; i < v; i++)
	{
		if(edges[sv][i] == 1 && !visited[i]){
			printDFS(edges, v, i, visited);
		}
	}
}

void DFS(int **edges, int v)
{
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	for(int i = 0; i < v; i++){
		if(!visited[i])
			printDFS(edges, v, i, visited);
	}

	delete [] visited;
}

int main()
{
	int v;
	int e;
	cin >> v >> e;

	int **edges = new int*[v];
	for(int i = 0; i < v; i++)
	{
		edges[i] = new int[v];
		for(int j = 0; j < v; j++)
		{
			edges[i][j] = 0;
		}
	}

	for(int i = 0; i < e; i++)
	{
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	DFS(edges, v);

	for(int i = 0; i < v; i++){
		delete [] edges[i];
	}

	delete [] edges;
	return 0;
}

