#include<bits/stdc++.h>
using namespace std;

int minArrowsRequired(int *arr, int n, bool *poped) {

	int minArrows = 0;
	for(int i = 0; i < n; i++) {
		int h = arr[i];
		if(!poped[i]) {
			poped[i] = true;
			minArrows++;
			for(int j = i+1; j < n; j++) {
				if(arr[j] == h-1) {
					poped[j] = true;
					h = h-1;
				}
			}
		}
	}

	return minArrows;
}

int main() {

	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bool *poped = new bool[n]();

	int ans = minArrowsRequired(arr, n, poped);

	cout << ans << endl;


	delete [] arr;
	delete [] poped;
	return 0;
}