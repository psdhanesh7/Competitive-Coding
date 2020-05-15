#include<bits/stdc++.h>
using namespace std;

int getMinDragonFires(long *pos, int n, int r, long start) {

	if(n <= 0) {
		return 0;
	}
	long *eliminated = lower_bound(pos, pos + n, start + r);
	for(int i = 0; i < n; i++) {
		cout << pos[i] << " ";
	}
	cout << endl;
	cout << eliminated - pos << endl;

	if(*eliminated == start + r) {
		eliminated++;
	}

	int newN = n - (eliminated - pos);
	int last = 0;
	int i = n-1;
	while(pos[i] == pos[n-1]) {
		last++;
		i--;
	}

	newN -= last;
	int ans = getMinDragonFires(eliminated, newN, r, start+r);

	return 1 + ans;
}
int main () {

	int q;
	cin >> q;

	while(q--) {
		int n, r;
		cin >> n >> r;

		long *pos = new long[n];
		for(int i = 0; i < n; i++) {
			cin >> pos[i];
		}

		sort(pos, pos+n);

		int ans = getMinDragonFires(pos, n, r, 0);

		cout << ans << endl;

		delete [] pos;
	}
	return 0;
}