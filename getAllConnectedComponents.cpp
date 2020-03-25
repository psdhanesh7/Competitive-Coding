#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int currentVertex, unordered_set<int>* component, bool *visited) {

	visited[currentVertex] = true;

	component->insert(currentVertex);

	for(int i = 0; i < edges[currentVertex].size(); i++) {
		int next = edges[currentVertex][i];

		if(!visited[next]) {
			dfs(edges, next, component, visited);
		}
	}
}

unordered_set<unordered_set<int>*>* getConnectedComponents(vector<int> *edges, int v) {

	bool *visited = new bool[v]();

	unordered_set<unordered_set<int>*>* connectedComponents = new unordered_set<unordered_set<int>*>();

	for(int i = 0; i < v; i++) {
		if(!visited[i]) {
			unordered_set<int>* component = new unordered_set<int>();
			dfs(edges, i, component, visited);

			connectedComponents->insert(component);
		}
	}

	delete [] visited;

	return connectedComponents;
}

int main() {

	int v, e;
	cin >> v >> e;

	vector<int> *edges = new vector<int>[v];
	for(int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;

		edges[f-1].push_back(s-1);
		edges[s-1].push_back(f-1);
	}

	unordered_set<unordered_set<int>*> *connectedComponents;
	connectedComponents = getConnectedComponents(edges, v);

	unordered_set<unordered_set<int>*> :: iterator it1;
	unordered_set<int> :: iterator it2;

	for(it1 = connectedComponents->begin(); it1 != connectedComponents->end(); it1++) {
		unordered_set<int>* component = *it1;
		for(it2 = component->begin(); it2 != component->end(); it2++) {
			cout << *it2 + 1<< " " ;
		}
		cout << endl;
	}

	delete connectedComponents;
	delete [] edges;

	return 0;
}