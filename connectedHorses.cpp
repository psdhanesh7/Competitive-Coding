// Connected horses

// You all must be familiar with the chess-board having 
// 8*8 squares of alternate black and white cells. Well, here 
// we have for you a similar 
// N*M size board with similar arrangement of black and white 
// cells.
// A few of these cells have Horses placed over them. 
// Each horse is unique. Now these horses are not the 
// usual horses which could jump to any of the 
// 8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
// A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
// 10^9+7

// Input:

// First line contains 
// T which is the number of test cases.
// T test cases follow first line of each containing three integers 
// N, M and Q where 
// N,M is the size of the board and 
// Q is the number of horses on it.

// Q lines follow each containing the 2 integers 
// X and Y which are the coordinates of the Horses.

// Output:

// For each test case, output the number of photographs taken by photographer.

// Constraints:

//  1<=T<=10
//  1<=N,M<=1000
//  1<=Q<=N*M

// SAMPLE INPUT

// 2
// 4 4 4
// 1 1
// 1 2
// 3 1
// 3 2
// 4 4 4
// 1 1
// 1 2
// 3 1
// 4 4

// SAMPLE OUTPUT

// 4
// 2

#include<bits/stdc++.h>
using namespace std;

long  M = 1e9+7;
long long fact[100000];

struct coordinates {
	int x;
	int y;
};

void calculateFact() {
	fact[0] = 1;
	for(int i = 1; i <= 100000; i++) {
		fact[i] = (fact[i-1] * i) % M;
	}
}

int dfs(vector<int> *edges, int currVertex, bool *visited) {

	visited[currVertex] = true;
	int count = 1;
	for(int i = 0; i < edges[currVertex].size(); i++) {
		int adjacent = edges[currVertex][i];
		if(!visited[adjacent]) {
			count += dfs(edges, adjacent, visited);
		}
	}

	return count;
}

long getPermutations(vector<int> *edges, int q) {

	bool *visited = new bool[q]();

	long permutations = 1;
	for(int i = 0; i < q; i++) {
		int componentCount = dfs(edges, i, visited);
		permutations = (permutations * fact[componentCount]) % M;
	}

	delete [] visited;

	return permutations;
}

bool swapPossible(coordinates c1, coordinates c2) {

	if((c2.x == c1.x-2 && c2.y == c1.y-1) || (c2.x == c1.x-2 && c2.y == c1.y+1) || (c2.x == c1.x-1 && c2.y == c1.y-2) || (c2.x == c1.x-1 && c2.y == c1.y+2)) {
		return true;
	}
	else if((c2.x == c1.x+1 && c2.y == c1.y-2) || (c2.x == c1.x+1 && c2.y == c1.y+2) || (c2.x == c1.x+2 && c2.y == c1.y-1) || (c2.x == c1.x+2 && c2.y == c1.y+1)) {
		return true;
	}

	return false;
}


int main() {

	int t;
	cin >> t;

	calculateFact();

	while(t--) {

		int n, m, q;
		cin >> n >> m >> q;

		unordered_map<int, coordinates> horses;
		unordered_set<coordinates> h;
		for(int i = 0; i < q; i++) {
			int x, y;
			coordinates pos;
			cin >> x >> y;

			pos.x = x;
			pos.y = y;

			horses[i] = pos;
			h.insert(pos);
		}

		vector<int> *edges = new vector<int>[q];

		for(int i = 0; i < horses.size(); i++) {
			for(int j = i+1; j < horses.size(); j++) {
				if(i == j) {
					continue;
				}

				if(swapPossible(horses[i], horses[j])) {
					edges[i].push_back(j);
					edges[j].push_back(i);
				}
			}
		}

		long permutations = getPermutations(edges, q);

		cout << permutations << endl;

		delete [] edges;
	}

	return 0;
}