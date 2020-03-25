#include<bits/stdc++.h>
using namespace std;

struct traingle {
	int a, b, c;
	int perimeter;
};

int main() {

	int n;
	cin >> n;

	int *ar = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> ar[i] ;
	}

	sort(ar, ar+n);

	traingle maxTriangle;
	maxTriangle.perimeter = INT_MIN;
	for(int i = 0; i < n-2; i++) {

		if(ar[i] + ar[i+1] > ar[i+2]) {
			int perimeter = ar[i] + ar[i+1] + ar[i+2];
			if(perimeter > maxTriangle.perimeter) {

				maxTriangle.a = ar[i];
				maxTriangle.b = ar[i+1];
				maxTriangle.c = ar[i+2];
				maxTriangle.perimeter = perimeter;
			}
			else if(perimeter == maxTriangle.perimeter) {

				if(ar[i+2] > maxTriangle.c) {
					maxTriangle.a = ar[i];
					maxTriangle.b = ar[i+1];
					maxTriangle.c = ar[i+2];
					maxTriangle.perimeter = perimeter;					
				}
				else if(ar[i+2] == maxTriangle.c) {
					if(ar[i] > maxTriangle.a) {

						maxTriangle.a = ar[i];
						maxTriangle.b = ar[i+1];
						maxTriangle.c = ar[i+2];
						maxTriangle.perimeter = perimeter;
					}
				}
			}
		}
	}

	if(maxTriangle.perimeter != INT_MIN) {
		cout << maxTriangle.a << " " << maxTriangle.b << " " << maxTriangle.c << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;


}