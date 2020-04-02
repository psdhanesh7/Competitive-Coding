// Note : Any graph with odd length cycles will not be bipartite

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool isBipartite(vector<int> *edges, int n) {

	if(n == 0) {
		return true;
	}

	unordered_set<int> sets[2];
	vector<int> pending;

	sets[0].insert(0);
	pending.push_back(0);

	while(pending.size() > 0) {
		int current = pending.back();
		pending.pop_back();

		int currentSet = sets[0].count(current) > 0 ? 0 : 1;

		for(int i = 0; i < edges[current].size(); i++) {

			int neighbor = edges[current][i];

			if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0) {
				sets[1 - currentSet].insert(neighbor);
				pending.push_back(neighbor);
			}
			else if(sets[currentSet].count(neighbor) > 0) {
				return false;
			}
		}
	}

	return true;

}

int main() {

	int n;
	while(true) {
		cin >> n;
		if(n == 0) {
			break;
		}

		vector<int> *edges = new vector<int>[n];

		int m;
		cin >> m;
		for(int i = 0; i < m; i++) {
			int f, s;
			cin >> f >> s;

			edges[f].push_back(s);
			edges[s].push_back(f);
		}

		bool ans = isBipartite(edges, n);

		if(ans) {
			cout << "Bicolourable" << endl;
		}
		else {
			cout << "Not Bicolourable" << endl;
		}

		delete [] edges;
	}
	return 0;
}