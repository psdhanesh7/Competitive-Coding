#include<bits/stdc++.h>
using namespace std;

int getMinVertex(bool *visited, int *distance, int v) {

	int minVertex = -1;
	
	for(int i = 0; i < v; i++) {
		if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
			minVertex = i;
		}
	}

	return minVertex;
}

void dijsktras(int **edges, int v) {

	bool *visited = new bool[v]();
	int *distance = new int[v];

	for(int i = 1; i < v; i++) {
		distance[i] = INT_MAX;
	}
	distance[0] = 0;

	for(int i = 0; i < v-1; i++) {
		// Get the unvisited vertex with minimum distance
		int minVertex = getMinVertex(visited, distance, v);

		visited[minVertex] = true;
		for(int j = 0; j < v; j++) {
			if(edges[minVertex][j] != 0 && !visited[j]) {
				if(distance[minVertex] + edges[minVertex][j] < distance[j]) {
					distance[j] = distance[minVertex] + edges[minVertex][j];
				}
			}
		}
	}

	// Print the output 
	for(int i = 0; i < v; i++) {
		cout << i << " " << distance[i] << endl;
	}

	delete [] visited;
	delete [] distance;
}

int main() {

	int v, e;
	cin >> v >> e;

	int **edges = new int*[v];
	for(int i = 0; i < v; i++) {
		edges[i] = new int[v]();
	}

	for(int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;

		edges[f][s] = weight;
		edges[s][f] = weight;
	}

	dijsktras(edges, v);

	for(int i = 0; i < v; i++) {
		delete [] edges[i];
	}
	delete [] edges;

	return 0;
}