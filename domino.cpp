#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> *edges, int currVertex, bool *visited, stack<int> &finishedVertices) {

	visited[currVertex] = true;

	for(int i = 0; i < edges[currVertex].size(); i++) {
		int adjacent = edges[currVertex][i];
		if(!visited[adjacent]) {
			dfs(edges, adjacent, visited, finishedVertices);
		}
	}

	finishedVertices.push(currVertex);
}

void dfs2(vector<int> *edges, int currVertex, bool *visited) {

	visited[currVertex] = true;

	for(int i = 0; i < edges[currVertex].size(); i++) {
		int adjacent = edges[currVertex][i];
		if(!visited[adjacent]) {
			dfs2(edges, adjacent, visited);
		}
	}
}

int getMinDominos(vector<int> *edges, int n) {

	bool *visited = new bool[n]();
	stack<int> finishedVertices;

	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			dfs(edges, i, visited, finishedVertices);
		}
	}

	delete [] visited;
	visited = new bool[n]();

	int minDominos = 0;
	while(!finishedVertices.empty()) {
		int element = finishedVertices.top();
		finishedVertices.pop();

		if(visited[element]) {
			continue;
		}

		minDominos++;
		dfs2(edges, element, visited);
	}

	delete [] visited;

	return minDominos;
}


int main() {

	int t;
	cin >> t;

	while(t--) {
		int n, m;
		cin >> n >> m;

		vector<int> *edges = new vector<int>[n];		
		for(int i = 0; i < m; i++) {
			int j, k;
			cin >> j >> k;
			edges[j-1].push_back(k-1);
		}

		int minDominos = getMinDominos(edges, n);

		cout  << minDominos << endl;

		delete [] edges;
	}

	return 0;
}