#include<bits/stdc++.h>
using namespace std;

long modExp(long a, string b, int m) {

	long result = 1;

	for(int i = b.length()-1; i >= 0; i--) {
		int d = b[i] - '0';
		if(d == 1) {
			result = (result * a) % m;
		}
		else if(d == 2) {
			result = (((result * a)%m)*a)%m;
		}

		a = ((a*a)%m*a)%m;
	}

	return (result + m) % m;
}

int main() {

	int t; 
	cin >> t;

	while(t--) {
		long a;
		string s;
		int m;

		cin >> a >> s >> m;

		long ans = modExp(a, s, m);

		cout << ans << endl;
	}

	return 0;
}