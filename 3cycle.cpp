#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
	int **graph = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		graph[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			graph[i][j] = 0;
		}
	}

	for(int i = 0; i < m; i++) {
		graph[u[i]][v[i]] = 1;
		graph[v[i]][u[i]] = 1;
	}

	int count = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {

			if(i != j && graph[i][j] == 1) {

				for(int k = 1; k <= n; k++) {
					if(k != i) {
						if(graph[j][k] == 1 ){
							if(graph[k][i] == 1) {
								count++;
						}
					}
					}
					
				}
			}

		}
	}

	for(int i = 0; i <= n; i++) {
		delete [] graph[i];
	}
	delete [] graph;

	int ans = count / 6; // I will be getting the same cycle 6 times because we are not marking visited
	// ie starting from each of the three vertex, i will get the same cycle in clockwise and anticlockwise direction
	return ans;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}