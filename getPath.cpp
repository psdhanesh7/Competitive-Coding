#include<iostream>
#include<vector>
using namespace std;

vector<int> getPath(int **edges, int v, int source, int destination, bool *visited)
{
	vector<int> path;

	if(source == destination)
	{
		visited[source] = true;
		path.push_back(source);

		return path;
	}

	visited[source] = true;
	for(int i = 0; i < v; i++)
	{
		if(edges[source][i] == 1 && !visited[i])
		{
			path = getPath(edges, v, i, destination, visited);
			if(path.size() != 0)
			{
				path.push_back(source);
				return path;
			}
		}
	}

	return path;
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

	int source, destination;
	cin >> source >> destination;

	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	vector<int> path;
	path = getPath(edges, v, source, destination, visited);

	for(int i = 0; i < path.size(); i++){
		cout << path[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < v; i++){
		delete [] edges[i];
	}

	delete [] edges;
	delete [] visited;
	return 0;

}