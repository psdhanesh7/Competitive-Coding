#include<bits/stdc++.h>
using namespace std;

vector<int> getPath(int **edges, int v, int source, int destination)
{	
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++){
		visited[i] = false;
	}

	queue<int> q;
	q.push(source);

	vector<int> path;
	unordered_map<int, int> adjacentVertices;
	while(!q.empty())
	{
		int currentVertex = q.front();
		q.pop();

		if(currentVertex == destination)
		{	
			path.push_back(currentVertex);	
			while(currentVertex != source)
			{
				currentVertex = adjacentVertices[currentVertex];
				path.push_back(currentVertex);
			}

			return path;
		}

		for(int i = 0; i < v; i++)
		{
			if(edges[currentVertex][i] == 1 && !visited[i]){
				q.push(i);
				adjacentVertices[i] = currentVertex;
				visited[i] = true;
			}
		}
	}

	delete [] visited;

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

	// bool *visited = new bool[v];
	// for(int i = 0; i < v; i++){
	// 	visited[i] = false;
	// }

	vector<int> path;
	path = getPath(edges, v, source, destination);

	for(int i = 0; i < path.size(); i++){
		cout << path[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < v; i++){
		delete [] edges[i];
	}

	delete [] edges;
	// delete [] visited;
	return 0;

}