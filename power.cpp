#include<iostream>
using namespace std;

int power(int x, int n){

	if(n == 0){
		return 1;
	}

	int smallAns = power(x, n-1);
	int ans = x * smallAns;

	return ans;
}

int main() {
	// Write your code here
    int x, n;
    cin >> x >> n;
    
    int ans = power(x,n);
    
    cout << ans << endl;
    
	return 0;
}
