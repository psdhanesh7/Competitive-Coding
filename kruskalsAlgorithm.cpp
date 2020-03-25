// Kruskal's Algorithm

// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -

// v1 v2 w

// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :

// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

// Output Format :

// MST

// Constraints :
// 2 <= V, E <= 10^5
// Sample Input 1 :

// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8

// Sample Output 1 :

// 1 2 1
// 0 1 3
// 0 3 5


#include<bits/stdc++.h>
using namespace std;

class Edge {
	public :
		int src;
		int dest;
		int weight;
};

int getParent(int *parent, int v) {
	if(v == parent[v]) {
		return v;
	}

	return getParent(parent, parent[v]);
}

bool compare(Edge e1, Edge e2) {

	return e1.weight < e2.weight;
}

Edge* kruskals(Edge *edges, int v, int e) {

	sort(edges, edges + e, compare);

	Edge *output = new Edge[v-1];
	int *parent = new int[v];

	for(int i = 0; i < v; i++) {
		parent[i] = i;
	}

	int count = 0;
	int i = 0;
	while(count < v-1) {
		Edge currentEdge = edges[i];

		int scrParent = getParent(parent, currentEdge.src);
		int destParent = getParent(parent, currentEdge.dest);

		// union algorithm for checking if a cycle will be formed from selecting this edge
		// Note : this union find algorithm takes O(v) time, which increases the overall time complexity
		// We can reduce the time complexity if we use union by rank and path compressin algorithm for detecting the cycle
		// This algorithm takes O(log v) time
		if(scrParent != destParent) {
			output[count] = currentEdge;
			count++;
			parent[scrParent] = destParent;
		}

		i++;
	}

	delete [] parent;

	return output;
}

int main() {

	int v, e;
	cin >>  v >> e;

	Edge *edges = new Edge[e];
	for(int i = 0; i < e; i++) {
		cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
	}

	Edge *mst = kruskals(edges, v, e);

	for(int i = 0; i < v-1; i++) {
		if(mst[i].src < mst[i].dest) {
			cout << mst[i].src << " " << mst[i].dest << " " << mst[i].weight << endl;  
		}
		else {
			cout << mst[i].dest << " " << mst[i].src << " " << mst[i].weight << endl;
		}
	}

	delete [] mst;

	return 0;
}

// Note : the overall time complexity of kruskals algorithm is eloge + e*v (incase of union find algorihtm)