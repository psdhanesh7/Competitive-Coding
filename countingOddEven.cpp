// Counting Even/Odd

// Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-

// Query 0 :- modify the element present at index i to x.
// Query 1:- count the number of even numbers in range l to r inclusive.
// Query 2:- count the number of odd numbers in range l to r inclusive.

// Input:

// First line of the input contains the number N. Next line contains N natural numbers. 
// Next line contains an integer Q followed by Q queries.

// 0 x y - modify the number at index x to y. 

// 1 x y - count the number of even numbers in range l to r inclusive.

// 2 x y - count the number of odd numbers in range l to r inclusive.

// Constraints:

// 1<=N,Q<=10^5

// 1<=l<=r<=N 

// 0<=Ai<=10^9

// 1<=x<=N

// 0<=y<=10^9

// Note:-
// indexing starts from 1.
// Sample Input

// 6
// 1 2 3 4 5 6
// 4
// 1 2 5
// 2 1 4
// 0 5 4
// 1 1 6

// Sample Output

// 2
// 2
// 4

#include<bits/stdc++.h>
using namespace std;

struct node {
	int odd;
	int even;
};

void buildTree(int *ar, node *tree, int start, int end, int treeIndex) {

	if(start == end) {

		tree[treeIndex].odd = ar[start] % 2;
		tree[treeIndex].even = 1 - ar[start] % 2;

		return;
	}

	int mid = (start + end)/2;

	buildTree(ar, tree, start, mid, 2*treeIndex);
	buildTree(ar, tree, mid+1, end, 2*treeIndex + 1);

	tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex+1].odd;
	tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
}

void updateTree(int *ar, node *tree, int start, int end, int treeIndex, int index, int value) {

	if(start == end) {

		ar[index] = value;
		tree[treeIndex].odd = ar[start] % 2;
		tree[treeIndex].even = 1 - ar[start] % 2;

		return ;
	}

	int mid = (start + end)/2;

	if(index <= mid) {
		updateTree(ar, tree, start, mid, 2*treeIndex, index, value);
	}
	else {
		updateTree(ar, tree, mid+1, end, 2*treeIndex+1, index, value);
	}

	tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex + 1].odd;
	tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
}

node queryTree(node *tree, int start, int end, int treeIndex, int left, int right) {

	if(start > right || end < left) {

		node ans;
		ans.odd = 0;
		ans.even = 0;

		return ans;
	}
	if(start >= left && end <= right) {
		return tree[treeIndex];
	}

	int mid = (start + end)/2;

	node ans1 = queryTree(tree, start, mid, 2*treeIndex, left, right);
	node ans2 = queryTree(tree, mid+1, end, 2*treeIndex+1, left, right);

	node ans;
	ans.odd = ans1.odd + ans2.odd;
	ans.even = ans1.even + ans2.even;

	return ans;

}

int main() {

	int n;
	cin >> n;

	int *ar = new int[n];
	for(int i = 0; i < n ;i++) {
		cin >> ar[i];
	}

	node *tree = new node[3*n];
	buildTree(ar, tree, 0, n-1, 1);

	int q;
	cin >> q;

	while(q--) {

		int query, left, right, index, value;
		node ans;

		cin >> query;

		switch(query) {

			case 0 : cin >> index >> value;
					 updateTree(ar, tree, 0, n-1, 1, index-1, value);

					 break;
			case 1 : cin >> left >> right;
					 ans = queryTree(tree, 0, n-1, 1, left-1, right-1);
					 cout << ans.even << endl;

					 break;
			case 2 : cin >> left >> right;
					 ans = queryTree(tree, 0, n-1, 1, left-1, right-1);
					 cout << ans.odd << endl;

					 break;
		}

	}

	delete [] ar;
	delete [] tree;

	return 0;
}