#include<bits/stdc++.h>
using namespace std;

void getTriplet(int ar[], int n, int sum, string output) {

	if(sum == 0) {
		cout << output << endl;
		return;
	} 
	if(n == 0 || sum < 0) {
		return;
	}

	getTriplet(ar, n, sum - ar[n-1], output + to_string(ar[n-1]) + " " );
	getTriplet(ar, n-1, sum, output);
}

int main() {

	int ar[] = {1, 3, 5, 7, 9, 11, 13, 15};

	getTriplet(ar, 8, 30, "");

	return 0;

}