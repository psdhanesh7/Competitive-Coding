#include<iostream>
using namespace std;

bool printDFS(int **edges, int v, int sv, int destination, bool *visited)
{
	if(sv == destination){
		return true;
	}

	visited[sv] = true;

	for(int i = 0; i < v; i++)
	{
		if(edges[sv][i] == 1 && !visited[i]){
			if(printDFS(edges, v, i, destination, visited)){
				return true;
			}
		}
	}

	return false;
}

bool DFS(int **edges, int v, int source, int destination)
{
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	bool hasPath = printDFS(edges, v, source, destination, visited);

	delete [] visited;
	return hasPath;
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

	int source, destinaiton;
	cin >> source >> destinaiton;

	bool hasPath = DFS(edges, v, source, destinaiton);
	if(hasPath){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}

	for(int i = 0; i < v; i++){
		delete [] edges[i];
	}

	delete [] edges;
	return 0;
}

