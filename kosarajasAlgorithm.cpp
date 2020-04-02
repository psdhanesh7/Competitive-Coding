#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int currVertex, bool *visited, stack<int> &finishedVertices) 
{
	visited[currVertex] = true;

	for(int i = 0; i < edges[currVertex].size(); i++) 
	{
		int adjacent = edges[currVertex][i];
		if(!visited[adjacent]) 
		{
			dfs(edges, adjacent, visited, finishedVertices);
		}
	}

	finishedVertices.push(currVertex);
}

void dfs2(vector<int> *edges, int currVertex, bool *visited, unordered_set<int>* component) 
{
	visited[currVertex] = true;
	component->insert(currVertex);

	for(int i = 0; i < edges[currVertex].size(); i++) 
	{
		int adjacent = edges[currVertex][i];
		if(!visited[adjacent]) 
		{
			dfs2(edges, adjacent, visited, component);
		}
	}
}

unordered_set<unordered_set<int>*>* getStronglyConnectedComponents(vector<int> *edges, vector<int> *edgesT, int n) 
{
	bool *visited = new bool[n]();
	stack<int> finishedVertices;

	for(int i = 0; i < n; i++) 
	{
		if(!visited[i]) 
		{
			dfs(edges, i, visited, finishedVertices);
		}
	}

	delete [] visited;
	visited = new bool[n]();

	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();

	while(!finishedVertices.empty()) 
	{
		int element = finishedVertices.top();
		finishedVertices.pop();

		if(visited[element]) 
		{
			continue;
		}
		unordered_set<int>* component = new unordered_set<int>();

		dfs2(edgesT, element, visited, component);
		output->insert(component);	
	}
	delete [] visited;

	return output	;
}

int main() 
{
	int n;
	cin >> n;

	vector<int> *edges = new vector<int>[n];
	vector<int> *edgesT = new vector<int>[n];

	int m;
	cin >> m;

	for(int i = 0; i < m; i++) 
	{
		int j, k;
		cin >> j >> k;

		edges[j-1].push_back(k-1);
		edgesT[k-1].push_back(j-1);
	}

	unordered_set<unordered_set<int>*> *components = getStronglyConnectedComponents(edges, edgesT, n);

	unordered_set<unordered_set<int>*> :: iterator it = components->begin();
	while(it != components->end()) 
	{
		unordered_set<int>* component = *it;

		unordered_set<int> :: iterator it2 = component->begin();
		while(it2 != component->end()) 
		{
			cout << *it2 + 1 << " ";
			it2++;
		}
		cout << endl;
		delete component;
		it++;
	} 

	delete [] edges;
	delete [] edgesT;
	delete components;

	return 0;
}