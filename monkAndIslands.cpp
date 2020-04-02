// Monk and the Islands

// MONK AND THE ISLAND

// Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
// Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

// Input:

// First line contains T. T testcases follow.
// First line of each test case contains two space-separated integers N, M.
// Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

// Output:

// Print the answer to each test case in a new line.

// Constraints:

// 1 ≤ T ≤ 10
// 1 ≤ N ≤ 10000
// 1 ≤ M ≤ 100000
// 1 ≤ X, Y ≤ N

// SAMPLE INPUT

// 2
// 3 2
// 1 2
// 2 3
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2

// SAMPLE OUTPUT

// 2
// 2


#include<bits/stdc++.h>
using namespace std;

int getShortestDistance(vector<int> *edges, int n) {

	bool *visited = new bool[n]();
	int *distance = new int[n]();

	queue<int> q;
	q.push(0);
	distance[0] = 0;

	while(!q.empty()) {
		int element = q.front();
		q.pop();

		for(int i = 0; i < edges[element].size(); i++) {
			int adjacent = edges[element][i];

			if(!visited[adjacent]) {
				q.push(adjacent);
				visited[adjacent] = true;
				distance[adjacent] = distance[element] + 1;
			}
		}
	}

	int ans = distance[n-1];

	delete [] visited;
	delete [] distance;

	return ans;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		int n, m;
		cin >> n >> m;

		vector<int> *edges = new vector<int>[n];

		for(int i = 0; i < m; i++) {
			int f, s;
			cin >> f >> s;

			edges[f-1].push_back(s-1);
			edges[s-1].push_back(f-1);
		}

		int shortestDistance = getShortestDistance(edges, n);

		cout << shortestDistance << endl;

		delete [] edges;
	}

	return 0;
}