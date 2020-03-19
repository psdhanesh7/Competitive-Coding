#include<bits/stdc++.h>
using namespace std;

int solve(string S,string V)
{
	// Write your code here.

	if(S == "") {
		return 0;
	}

	int option1 = solve(S.substr(1), V);
	int i;
	for(i = 0; i < V.length(); i++) {
		if(V[i] == S[0]) {
			break;
		}
	}

	int option2 = 1 + solve(S.substr(1), V.substr(i+1));

	int ans = min(option1, option2);
	return ans;
}

int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}