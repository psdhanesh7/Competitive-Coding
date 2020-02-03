#include<iostream>
#include<queue>
using namespace std;

void BFS(int **edges, int v, int sv, bool *visited)
{
	queue<int> q;
	q.push(sv);
	visited[sv] = true;

	while(!q.empty())
	{
		int value = q.front();
		q.pop();
		for(int i = 0; i < v; i++)
		{
			if(edges[value][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

bool isConnected(int **edges, int v)
{
	

	bool *visited = new bool[v];
	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	BFS(edges, v, 0, visited);

	for(int i = 0; i < v; i++)
	{
		if(!visited[i])
		{
			delete [] visited;
			return false;
		}
	}

	delete [] visited;
	return true;
}

int main()
{
	int v;
	int e;
	cin >> v >> e;

	int **edges = new int*[v];
	for(int i = 0; i < v; i++){
		edges[i] = new int[v];
		for(int j = 0; j < v; j++){
			edges[i][j] = 0;
		}
	}

	int f, s;
	for(int i = 0; i < e; i++){
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	bool connected = isConnected(edges, v);
	if(connected){
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