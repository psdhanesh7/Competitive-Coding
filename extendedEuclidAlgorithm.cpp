#include<iostream>
using namespace std;

class Triplet {
	public : 
		int x;
		int y;
		int gcd;
};


Triplet extendedEuclid(int a, int b) {

	if(b == 0) {
		Triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;

		return ans;
	}

	// Extended Euclid Algorithm
	Triplet smallAns = extendedEuclid(b, a%b);

	Triplet ans;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	ans.gcd = smallAns.gcd;

	return ans;

}

int main() {

	int a = 16;
	int b = 10;

	Triplet ans = extendedEuclid(a, b);

	cout << ans.x << endl;
	cout << ans.y << endl;
	cout << ans.gcd << endl;

	return 0;
}