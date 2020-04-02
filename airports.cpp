// AIRPORTS

// The government of a certain developing nation wants to improve transportation in one of its most inaccessible areas, in an attempt to attract investment. The region consists of several important locations that must have access to an airport.
// Of course, one option is to build an airport in each of these places, but it may turn out to be cheaper to build fewer airports and have roads link them to all of the other locations. Since these are long distance roads connecting major locations in the country (e.g. cities, large villages, industrial areas), all roads are two-way. Also, there may be more than one direct road possible between two areas. This is because there may be several ways to link two areas (e.g. one road tunnels through a mountain while the other goes around it etc.) with possibly differing costs.
// A location is considered to have access to an airport either if it contains an airport or if it is possible to travel by road to another location from there that has an airport. You are given the cost of building an airport and a list of possible roads between pairs of locations and their corresponding costs. The government now needs your help to decide on the cheapest way of ensuring that every location has access to an airport. The aim is to make airport access as easy as possible, so if there are several ways of getting the minimal cost, choose the one that has the most airports.

// Input

// The first line of input contains the integer T (T < 25), the number of test cases. The rest of the input consists of T cases. Each case starts with two integers N, M and A (0 < N ≤ 10, 000, 0 ≤ M ≤ 100, 000, 0 < A ≤ 10, 000) separated by white space. N is the number of locations, M is the number of possible roads that can be built, and A is the cost of building an airport.
// The following M lines each contain three integers X, Y and C (1 ≤ X, Y ≤ N, 0 < C ≤ 10, 000), separated by white space. X and Y are two locations, and C is the cost of building a road between X and Y .

// Output

// Your program should output exactly T lines, one for each case. Each line should be of the form ‘Case #X: Y Z’, where X is the case number Y is the minimum cost of making roads and airports so that all locations have access to at least one airport, and Z is the number of airports to be built. As mentioned earlier, if there are several answers with minimal cost, choose the one that maximizes the number of airports.

// Sample Input

// 2
// 4 4 100
// 1 2 10
// 4 3 12
// 4 1 41
// 2 3 23
// 5 3 1000
// 1 2 20
// 4 5 40
// 3 2 30

// Sample Output

// Case #1: 145 1
// Case #2: 2090 2


#include<bits/stdc++.h>
using namespace std;

class Edge {
	public :
		int src;
		int dest;
		int weight;
};

int getParent(int *parent, int v) {

	if(parent[v] == v) {
		return v;
	}

	return getParent(parent, parent[v]);
}

bool compare(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

pair<int, int> getMinCost(Edge *edges, int m, int n, int airportCost) {

	sort(edges, edges + m, compare);

	int *parent = new int[n];
	for(int i = 0; i < n; i++ ){
		parent[i] = i;
	}

	int minCost = 0;

	int i = 0;
	int count = 0;

	while(i < m && count < n-1 && edges[i].weight < airportCost) {

		Edge currentEdge = edges[i];

		int srcParent = getParent(parent, currentEdge.src);
		int destParent = getParent(parent, currentEdge.dest);

		if(srcParent != destParent) {
			count++;
			minCost += currentEdge.weight;
			parent[srcParent] = destParent;
		}

		i++;
	}

	set<int> parentSet;
	for(int i = 0; i < n; i++ ) {
		parentSet.insert(getParent(parent, i));
	}

	int airports = parentSet.size();

	delete [] parent;

	return make_pair(airports * airportCost + minCost, airports);
}

int main() {

	int t;
	cin >> t;

	int caseNo = 1;

	while (t--) {

		int n, m, a;
		cin >> n >> m >> a;

		Edge *edges = new Edge[m];
		for(int i = 0; i < m; i++) {
			int src, dest, weight;
			cin >> src >> dest >> weight;

			edges[i].src = src - 1;
			edges[i].dest = dest - 1;
			edges[i].weight = weight;
		}

		pair<int, int> ans = getMinCost(edges, m, n, a);

		cout << "Case #" << caseNo << ": " << ans.first << " " << ans.second << endl;


		delete [] edges;
		caseNo++;
	}

	return 0;
}