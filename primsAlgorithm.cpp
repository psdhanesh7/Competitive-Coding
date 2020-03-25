#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited, int *weight, int v) {

	int minVertex = -1;

	for(int i = 0; i < v; i++) {
		if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
			minVertex = i;
		}
	}

	return minVertex;
}

void prims(int **edges, int v) {

	int *parent = new int[v];
	int *weight = new int[v];
	bool *visited = new bool[v]();

	for(int i = 1; i < v; i++) {
		weight[i] = INT_MAX;
	}

	parent[0] = -1;
	weight[0] = 0;

	for(int i = 0; i < v-1; i++) {

		// Get minVertex, ie, unvisited vertex with minimum weight
		int minVertex = getMinVertex(visited, weight, v);

		visited[minVertex] = true;
		// Explore all the neighbours of minVertex and update parent and weight array according to that
		for(int j = 0; j < v; j++) {
			if(edges[minVertex][j] != 0 && edges[minVertex][j] < weight[j] && !visited[j]) {
				parent[j] = minVertex;
				weight[j] = edges[minVertex][j];
			}
		}
	}

	for(int i = 1; i < v; i++) {
		if(parent[i] < i) {
			cout << parent[i] << " " << i << " " << weight[i] << endl; 
		}
		else {
			cout << i << " " << parent[i] << " " << weight[i] << endl; 
		}
	}

	delete [] parent;
	delete [] weight;
	delete [] visited;
}

int main() {

	int v, e;
	cin >> v >> e;

	int **edges = new int*[v];
	for(int i = 0; i < v; i++) {
		edges[i] = new int[v]();
	}

	for(int i = 0; i < e; i++) {
		int src, dest, weight;
		cin >> src >> dest >> weight;

		edges[src][dest] = weight;
		edges[dest][src] = weight;
	}

	prims(edges, v);


	for(int i = 0; i < v; i++) {
		delete [] edges[i];
	}
	delete [] edges;

	return 0;
}