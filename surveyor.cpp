// Surveyor

// A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
// The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
// Input Format

// String s
// Array of length of string

// Output Format

// Area

// Constraints

// direction will have between 4 and 50 characters inclusive.
// length will have the same number of elements as the number of characters in direction.
// Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
// Each element of length will be between 1 and 1000 inclusive.
// The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).

// Sample Test Case

// "NWWSE"
// {10,3,7,10,10}
// Returns: 100


// "NESWNWSW"
// {20,200,30,100,20,30,10,70}
// Returns: 4700



#include<bits/stdc++.h>
using namespace std;

class Point {
	public : 
		int x; 
		int y;
};

Point newPoint(char dir, int dist, Point p) {

	switch(dir) {
		case 'N' :	p.y += dist;
					break;
		case 'S' : 	p.y -= dist;
					break;
		case 'E' : 	p.x += dist;
					break;
		case 'W' :	p.x -= dist;
	}

	return p;
}

double polygonArea(string dirs, int *dist) {

	Point start;
	start.x = 0;
	start.y = 0;

	start = newPoint(dirs[0], dist[0], start);

	double area = 0;

	Point curr;
	curr.x = start.x;
	curr.y = start.y;

	Point next;
	int n = dirs.length();

	for(int i = 1; i < n-1; i++) {

		curr = newPoint(dirs[i], dist[i], curr);
		next = newPoint(dirs[i+1], dist[i+1], curr);

		int x1 = curr.x - start.x;
		int x2 = next.x - start.x;
		int y1 = curr.y - start.y;
		int y2 = next.y - start.y;

		area += (x1*y2) - (y1*x2);
	}

	return abs(area/2);
}

int main() {

	string dirs;
	cin >> dirs;

	int n = dirs.length();

	int *dist = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> dist[i];
	}

	long area = polygonArea(dirs, dist);

	cout << area << endl;

	delete [] dist;

	return 0;
}