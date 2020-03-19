#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void printComponent(vector<int> component)
{
	for(int i = 0; i < component.size(); i++){
		cout << component[i] << " ";
	}
}

vector<int> BFS(int **edges, int v, int sv, bool *visited)
{
	vector<int> component;
	queue<int> q;
	q.push(sv);
	visited[sv] = true;

	while(!q.empty())
	{
		int value = q.front();
		q.pop();
		component.push_back(value);
		for(int i = 0; i < v; i++)
		{
			if(edges[value][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return component;
}


vector<vector<int>> allConnectedComponents(int **edges, int v)
{
	vector<vector<int>> connectedComponents;
	bool *visited = new bool[v];
	for(int i = 0; i < v; i++)
	{
		visited[i] = false;
	}

	vector<int> component;
	for(int i = 0; i < v; i++)
	{
		if(!visited[i]){
			
			component = BFS(edges, v, i, visited);
			sort(component.begin(), component.end());
			connectedComponents.push_back(component);
		}
	}

	delete [] visited;
	return connectedComponents;
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

	vector<vector<int>> connectedComponents;
	connectedComponents = allConnectedComponents(edges, v);

	for(int i = 0; i < connectedComponents.size(); i++)
	{
		printComponent(connectedComponents[i]);
		cout << endl;
	}

	for(int i = 0; i < v; i++){
		delete [] edges[i];
	}

	delete [] edges;

	return 0;
}