// Minimum In SubArray

// Range Minimum Query
// Given an array A of size N, there are two types of queries on this array.
// 1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
// 2) u x y: In this query you need to update A[x]=y.
// Input:

// First line of the test case contains two integers, N and Q, size of array A and number of queries.
// Second line contains N space separated integers, elements of A.
// Next Q lines contain one of the two queries.

// Output:

// For each type 1 query, print the minimum element in the sub-array A[l:r].

// Contraints:

// 1≤N,Q,y≤10^5
// 1≤l,r,x≤N

// Sample Input :

// 5 5
// 1 5 2 4 3
// q 1 5
// q 1 3
// q 3 5
// u 3 6
// q 1 5

// Sample Output :

// 1
// 1
// 2
// 1

#include<bits/stdc++.h>
using namespace std;

void buildTree(int *ar, int *tree, int left, int right, int treeNode) {

	if(left == right) {
		tree[treeNode] = ar[left];
		return;
	}

	int mid = (left + right)/2;

	buildTree(ar, tree, left, mid, 2*treeNode);
	buildTree(ar, tree, mid+1, right, 2*treeNode+1);

	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateTree(int *ar, int *tree, int left, int right, int treeNode, int index, int value) {

	if(left == right) {
		ar[index] = value;
		tree[treeNode] = value;
		return; 
	}

	int mid = (left + right)/2;

	if(index <= mid) {
		updateTree(ar, tree, left, mid, 2*treeNode, index, value);
	}
	else {
		updateTree(ar, tree, mid+1, right, 2*treeNode+1, index, value);
	}

	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

int queryTree(int *tree, int start, int end, int treeNode, int left, int right) {

	// completely outside the given range
	if(end < left || start > right) {
		return INT_MAX;
	}
	// completely inside the given range
	if(start >= left && end <= right) {
		return tree[treeNode];
	}

	// paritilally inside the given range
	int mid = (start + end)/2;

	int option1 = queryTree(tree, start, mid, 2*treeNode, left, right);
	int option2 = queryTree(tree, mid+1, end, 2*treeNode+1, left, right);

	int ans = min(option1, option2);

	return ans;

}

int main() {

	int n, q;
	cin >> n >> q;

	int *ar = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int *tree = new int[4*n];

	buildTree(ar, tree, 0, n-1, 1);

	while(q--) {

		char query;
		cin >> query;

		int left, right, index, value, ans;

		switch(query) {

			case 'q' :  cin >> left >> right;
						ans = queryTree(tree, 0, n-1, 1, left-1, right-1);
						cout << ans << endl;

						break;
			case 'u' :  cin >> index >> value;
						updateTree(ar, tree, 0, n-1, 1, index-1, value);

						break;
		}
	}

	delete [] tree;
	delete [] ar;

	return 0;
}