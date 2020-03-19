#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printBFS(int **edges, int v, int sv, bool *visited)
{
	queue<int> q;
	q.push(sv);
	visited[sv] = true;

	while(!q.empty())
	{
		int value = q.front();
		q.pop();
		// cout << value << " ";
		for(int i = 0; i < v; i++)
		{
			if(edges[value][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int getConnectedGroups(int **edges, int n)
{
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(!visited[i]){
			count++;
			printBFS(edges, n, i, visited);
		}
	}

	delete [] visited;
	return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
	int **edges = new int*[n];
	for(int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for(int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}

	for(int i = 0; i < u.size(); i++)
	{
		int f = u[i]-1;
		int s = v[i]-1;

		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	int connectedGroups = getConnectedGroups(edges, n);

	for(int i = 0; i < n; i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
	return connectedGroups;
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