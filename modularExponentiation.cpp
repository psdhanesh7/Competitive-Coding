#include<bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int c) {

	int ans = 1;

	while(b > 0) {
		if(b&1 == 1) {
			ans = (ans * a)%c;
		}
		a = (a*a) % c;
		b /= 2;
	}

	return ans;
}

int main() {

	int a = 2;
	int b = 10;
	int c = 5;

	cout << modExp(a, b, c) << endl;

	return 0;
}