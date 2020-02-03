#include<bits/stdc++.h>
using namespace std;

int path[21][21];

void ratInAMazeHelper(int maze[][20], int n, int row, int col){

	if(row == n-1 && col == n-1){

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << path[i][j] << " " ;
			}
		}
		cout << endl;

		return;
	}

	//going up
	if(row - 1 >= 0 && path[row-1][col] != 1 && maze[row - 1][col] == 1){

		path[row-1][col] = 1;
		ratInAMazeHelper(maze, n, row-1, col);
		path[row-1][col] = 0;
	}

	//going down
	if(row + 1 < n && path[row+1][col] != 1 && maze[row+1][col] == 1){

		path[row+1][col] = 1;
		ratInAMazeHelper(maze, n, row+1, col);
		path[row+1][col] = 0;
	}

	//going left
	if(col - 1 >= 0 && path[row][col-1] != 1 && maze[row][col-1] == 1){
		path[row][col-1] = 1;
		ratInAMazeHelper(maze, n, row, col-1);
		path[row][col-1] = 0;
	}

	//going right
	if(col + 1 < n && path[row][col+1] != 1 && maze[row][col+1] == 1){
		path[row][col+1] = 1;
		ratInAMazeHelper(maze, n, row, col+1);
		path[row][col+1] = 0;
	}

}

void ratInAMaze(int maze[][20], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			path[i][j] = 0;
		}
	}

	path[0][0]  = 1;
	ratInAMazeHelper(maze, n,0, 0);
}

int main(){

	int n;
	int maze[20][20];

	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> maze[i][j];
		}		
	}

	ratInAMaze(maze, n);

	return 0;
}