#include<bits/stdc++.h>
using namespace std;

void buildTree(int ar[], int *tree, int start, int end, int treeIndex) {

	if(start == end) {
		tree[treeIndex] = ar[start];
		return; 
	}

	int mid = (start + end )/2;

	buildTree(ar, tree, start, mid, 2*treeIndex);
	buildTree(ar, tree, mid+1, end, 2*treeIndex+1);

	tree[treeIndex] = min(tree[2*treeIndex], tree[2*treeIndex + 1]);
}

void updateSegmentTreeLazy(int *tree, int *lazy, int low, int high, int curPos, int start, int end, int increment) {

	if (low > high) {
		return;
	}

	if(lazy[curPos] != 0) {
		tree[curPos] += lazy[curPos];
		// If it is not a leaf node, we need to update its children
		if(low != high) {
			lazy[2*curPos] += lazy[curPos];
			lazy[2*curPos + 1] += lazy[curPos];
		}

		lazy[curPos] = 0;
	}

	// completely outside the given range

	if(start > high || end < low) {
		return ;
	}

	// complete overlap

	if(low >= start && high <= end) {
		tree[curPos] += increment;
		// if not a leaf node, update it in the lazy tree
		if(low != high) {
			lazy[2*curPos] += increment;
			lazy[2*curPos + 1] += increment;
		}

		return ;
	}

	// partial overlap

	int mid = (low + high)/2;

	updateSegmentTreeLazy(tree, lazy, low, mid, 2*curPos, start, end, increment);
	updateSegmentTreeLazy(tree, lazy, mid+1, high, 2*curPos + 1, start, end, increment);

	tree[curPos] = min(tree[2*curPos], tree[2*curPos + 1]);
}

int main() {

	int ar[] = { 1, 3, -2, 4 };

	int *tree = new int[12];
	buildTree(ar, tree, 0, 3, 1);

	int *lazy = new int[12]();
	updateSegmentTreeLazy(tree, lazy, 0, 3, 1, 0, 3, 3);
	updateSegmentTreeLazy(tree, lazy, 0, 3, 1, 0, 1, 2);

	cout << "Segment Tree :" << endl;
	for(int i = 1; i < 12; i++) {
		cout << tree[i] << endl;
	}

	cout << "Lazy tree : " << endl;
	for(int i = 1; i < 12; i++) {
		cout << lazy[i] << endl;
	}

	delete [] tree;
	delete [] lazy;

	return 0;
}