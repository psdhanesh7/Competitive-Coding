// Permutation Swaps

// Kevin has a permutation P of N integers 1, 2, ..., N, but he doesn't like it. Kevin wants to get a permutation Q.

// Also he believes that there are M good pairs of integers (ai , bi). Kevin can perform following operation with his permutation:

// Swap Px and Py only if (x, y) is a good pair.
// Help him and tell if Kevin can obtain permutation Q using such operations.

// Input format:

// The first line of input will contain an integer T, denoting the number of test cases.

// Each test case starts with two space-separated integers N and M. The next line contains N space-separated integers Pi. The next line contains N space-separated integers Qi. Each of the next M lines contains two space-separated integers ai and bi.

// Output format:

// For every test case output "YES" (without quotes) if Kevin can obtain permutation Q and "NO" otherwise.

// Constraints:

// 1 ≤ T ≤ 10
// 2 ≤ N ≤ 100000
// 1 ≤ M ≤ 100000
// 1 ≤ Pi, Qi ≤ N. Pi and Qi are all distinct.
// 1 ≤ ai < bi ≤ N

// SAMPLE INPUT

// 2
// 4 1
// 1 3 2 4
// 1 4 2 3
// 3 4
// 4 1
// 1 3 2 4
// 1 4 2 3
// 2 4

// SAMPLE OUTPUT

// NO 
// YES


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

bool permutationPossible(vector<int> *edges, int n, int *p, int *q) {

	unordered_set<unordered_set<int>*> *connectedComponents;
	connectedComponents = getConnectedComponents(edges, n);

	unordered_set<unordered_set<int>*> :: iterator it1;
	unordered_set<int> :: iterator it2;

	for(it1 = connectedComponents->begin(); it1 != connectedComponents->end(); it1++) {
		unordered_set<int>* component = *it1;
		unordered_set<int> pElements, qElements;
		for(it2 = component->begin(); it2 != component->end(); it2++) {
			
			pElements.insert(p[*it2]);
			qElements.insert(q[*it2]);
		}

		unordered_set<int> :: iterator it3;
		for(it3 = pElements.begin(); it3 != pElements.end(); it3++) {
			if(qElements.find(*it3) == qElements.end()) {

				delete connectedComponents;
				delete [] edges;

				return false;
			}
		}
	}

	delete connectedComponents;
	delete [] edges;

	return true;
}

int main() {

	int t;
	cin >> t;
	while(t--) {

		int n, m;
		cin >> n >> m;

		int *p = new int[n];
		int *q = new int[n];

		for(int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> q[i];
		}

		vector<int> *edges = new vector<int>[n];
		for(int i = 0; i < m; i++) {
			int f, s;
			cin >> f >> s;

			edges[f-1].push_back(s-1);
			edges[s-1].push_back(f-1);
		}

		if(permutationPossible(edges, n, p, q)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		delete [] p;
		delete [] q;
	}

	return 0;
}