// Vasya vs Rhezo
// Send Feedback
// Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
// For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
// You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
// Input:

// First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
// Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
// Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
// Each of the next Q lines contains 2 integers Li and Ri.

// Output:

// For each Li and Ri, print the index of the warrior that Queen Vasya should choose.

// Constraints:
// 1≤ N,Q ≤10^6
// 1≤ Ai,Bi ≤10^9
// 1≤Li≤Ri
// Sample Input

// 5
// 1 8 4 6 8
// 4 8 6 3 7
// 4
// 1 4
// 2 4
// 3 4
// 1 5

// Sample Output

// 2
// 2
// 4
// 2


#include<bits/stdc++.h>
using namespace std;

struct node {
	int a, b;
	int index;
};

void buildTree(node *ar, node *tree, int start, int end, int treeIndex) {

	if(start == end) {

		tree[treeIndex] = ar[start];
		tree[treeIndex].index = start + 1;

		return ;
	}

	int mid = (start + end)/2;

	buildTree(ar, tree, start, mid, 2*treeIndex);
	buildTree(ar, tree, mid+1, end, 2*treeIndex+1);

	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex + 1];

	if(left.a > right.a) {
		tree[treeIndex] = left;
	}
	else if(right.a > left.a) {
		tree[treeIndex] = right;
	}
	else {

		if(left.b > right.b) {
			tree[treeIndex] = left;
		}
		else if(right.b > left.b) {
			tree[treeIndex] = right;
		}
		else {
			tree[treeIndex] = left;
		}
	}
}

node queryTree(node *tree, int start, int end, int treeIndex, int left, int right) {

	if(start > right || end < left) {

		node ans;
		ans.a = 0;
		ans.b = 0;
		ans.index = -1;

		return ans;
	}
	if(start >= left && end <= right) {
		return tree[treeIndex];
	}

	int mid = (start + end)/2;

	node ans1 = queryTree(tree, start, mid, 2*treeIndex, left, right);
	node ans2 = queryTree(tree, mid+1, end, 2*treeIndex+1, left, right);

	node ans;
	if(ans1.a > ans2.a) {
		ans = ans1;
	}
	else if(ans2.a > ans1.a) {
		ans = ans2;
	}
	else {
		
		if(ans1.b > ans2.b) {
			ans = ans1;
		}
		else if(ans2.b > ans1.b) {
			ans = ans2;
		}
		else {
			ans = ans1;
		}
	}

	return ans;

}

int main() {

	int n;
	cin >> n;

	node *ar = new node[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i].a;
	}
	for(int i = 0; i < n; i++) {
		cin >> ar[i].b;
	}

	node *tree = new node[3*n];

	buildTree(ar, tree, 0, n-1, 1);

	int q;
	cin >> q;

	while(q--) {
		int left, right;
		cin >> left >> right;

		node ans = queryTree(tree, 0, n-1, 1, left-1, right-1);

		cout << ans.index << endl;
	}


	delete [] ar;
	delete [] tree;

	return 0;
}