#include<bits/stdc++.h>
using namespace std;

long getValidDecks(long *ar, int n, long k) {

	map<int, int> vp;
	int i = 2;
	int no = k;
	while(i*i <= k) {
		if(no%i == 0) {
			vp[i]++;
			no /= i;
		}
		else {
			i++;
		}
	}

	map<int, int>  :: iterator it;
	for(it = vp.begin(); it != vp.end(); it++) {
		cout << it->first << " : " << it->second << endl; 
	}

	return 1;
}

int main() {

	int n;
	long k;
	cin >> n >> k;

	long *ar = new long[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	long ans = getValidDecks(ar, n, k);

	cout << ans << endl;

	delete [] ar;
	return 0;
}