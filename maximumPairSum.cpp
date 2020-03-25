// Maximum Pair Sum

// You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
// Update:
// This will be indicated in the input by a 'U' followed by space and then two integers i and x.

// U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.

// This operation sets the value of A[i] to x.
// Query:
// This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.

// Q x y, 1 ≤ x < y ≤ N.

// You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
// Input

// The first line of input consists of an integer N representing the length of the sequence. 
// Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.

// Output

//  Output the maximum sum mentioned above, in a separate line, for each Query.

// Input:

// 5
// 1 2 3 4 5
// 6
// Q 2 4
// Q 2 5
// U 1 6
// Q 1 5
// U 1 7
// Q 1 5

// Output:

// 7
// 9
// 11
// 12

#include<bits/stdc++.h>
using namespace std;

struct node {
	int maximum;
	int smaximum;
};

void buildTree(int *ar, node *tree, int start, int end, int treeIndex) {

	if(start == end) {

		tree[treeIndex].maximum = ar[start];
		tree[treeIndex].smaximum = INT_MIN;

		return;
	}

	int mid = (start + end)/2;

	buildTree(ar, tree, start, mid, 2*treeIndex);
	buildTree(ar, tree, mid+1, end, 2*treeIndex+1);

	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];

	tree[treeIndex].maximum = max(left.maximum, right.maximum);
	tree[treeIndex].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));
}

void updateTree(int *ar, node *tree, int start, int end, int treeIndex, int index, int value) {

	if(start == end) {

		ar[index] = value;
		tree[treeIndex].maximum = value;
		tree[treeIndex].smaximum = INT_MIN;

		return;
	}

	int mid = (start + end)/2;

	if(index <= mid) {
		updateTree(ar, tree, start, mid, 2*treeIndex, index, value);
	}
	else {
		updateTree(ar, tree, mid+1, end, 2*treeIndex+1, index, value);
	}

	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];

	tree[treeIndex].maximum = max(left.maximum, right.maximum);
	tree[treeIndex].smaximum = min(max(left.maximum, right.smaximum), max(right.maximum, left.smaximum));

}

node queryTree(node *tree, int start, int end, int treeIndex, int left, int right) {

	if(start > right || end < left) {
		node ans;
		ans.maximum = INT_MIN;
		ans.smaximum = INT_MIN;

		return ans;
	}
	if( start >= left && end <= right) {
		return tree[treeIndex];
	}
	
	int mid = (start + end)/2;

	node ans1 = queryTree(tree, start, mid, 2*treeIndex, left, right);
	node ans2 = queryTree(tree, mid+1, end, 2*treeIndex+1, left, right);

	node ans;
	ans.maximum = max(ans1.maximum, ans2.maximum);
	ans.smaximum = min(max(ans1.maximum, ans2.smaximum), max(ans2.maximum, ans1.smaximum));

	return ans;
}

int main() {

	int n; 
	cin >> n;

	int *ar = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	node *tree = new node[3*n];
	buildTree(ar, tree, 0, n-1, 1);

	int q;
	cin >> q;

	while(q--) {

		char query;
		cin >> query;

		int left, right, index, value;
		node ans;

		switch(query) {

			case 'Q' :  cin >> left >> right;
						ans = queryTree(tree, 0, n-1, 1, left-1, right-1);
						cout << ans.maximum + ans.smaximum << endl;

						break;
			case 'U' :  cin >> index >> value;
						updateTree(ar, tree, 0, n-1, 1, index-1, value);

						break;
		}
	}


	delete [] ar;
	delete [] tree;

	return 0;
}