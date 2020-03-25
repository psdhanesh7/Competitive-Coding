#include<bits/stdc++.h>
using namespace std;

struct node {

	int maxSum;
	int sum;
	int bestSuffixSum;
	int bestPrefixSum;
};

void buildTree(int *ar, node *tree, int start, int end, int treeIndex) {

	if(start == end) {

		tree[treeIndex].maxSum = ar[start];
		tree[treeIndex].sum = ar[start];
		tree[treeIndex].bestPrefixSum = ar[start];
		tree[treeIndex].bestSuffixSum = ar[start];

		return ;
	}

	int mid = (start + end)/2;

	buildTree(ar, tree, start, mid, 2*treeIndex);
	buildTree(ar, tree, mid+1, end, 2*treeIndex+1);

	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex + 1];

	tree[treeIndex].maxSum = max(left.maxSum, right.maxSum);
	tree[treeIndex].maxSum = max(left.sum + right.bestPrefixSum, tree[treeIndex].maxSum);
	tree[treeIndex].maxSum = max(right.sum + left.bestSuffixSum, tree[treeIndex].maxSum);
	tree[treeIndex].maxSum = max(left.bestSuffixSum + right.bestPrefixSum, tree[treeIndex].maxSum);

	tree[treeIndex].sum = left.sum + right.sum;
	tree[treeIndex].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);
	tree[treeIndex].bestSuffixSum = max(right.bestSuffixSum, right.sum + left.bestSuffixSum);

}

node queryTree(node *tree, int start, int end, int treeIndex, int left, int right) {

	if(start > right || end < left) {

		node ans;
		ans.maxSum = INT_MIN;
		ans.sum = INT_MIN;
		ans.bestPrefixSum = INT_MIN;
		ans.bestSuffixSum = INT_MIN;

		return ans;
	}

	if(start >= left && end <= right ) {
		return tree[treeIndex];
	}

	int mid = (start + end)/2;

	node ans1 = queryTree(tree, start, mid, 2*treeIndex, left, right);
	node ans2 = queryTree(tree, mid+1, end, 2*treeIndex + 1, left, right);

	node ans;

	ans.maxSum = max(ans1.maxSum, ans2.maxSum);
	ans.maxSum = max(ans1.sum + ans2.bestPrefixSum, ans.maxSum);
	ans.maxSum = max(ans2.sum + ans1.bestSuffixSum, ans.maxSum);
	ans.maxSum = max(ans1.bestSuffixSum + ans2.bestPrefixSum, ans.maxSum);

	ans.sum = ans1.sum + ans2.sum;
	ans.bestPrefixSum = max(ans1.bestPrefixSum, ans1.sum + ans2.bestPrefixSum);
	ans.bestSuffixSum = max(ans2.bestSuffixSum, ans2.sum + ans1.bestSuffixSum);

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
	for(int i = 1; i < 3*n; i++) {
		cout << tree[i].maxSum << " " << tree[i].sum << " " << tree[i].bestPrefixSum << " " << tree[i].bestSuffixSum << endl;
	}

	int q;
	cin >> q;
	while(q--) {

		int left, right;
		cin >> left >> right;

		node ans = queryTree(tree, 0, n-1, 1, left-1, right-1);

		cout << ans.maxSum << endl;
	}



	delete [] ar;
	delete [] tree;

	return 0;
}