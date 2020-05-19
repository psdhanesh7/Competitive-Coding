#include<bits/stdc++.h>
using namespace std;

class Point {
	public : 
		int x;
		int y;
};

bool compare(Point p1, Point p2) {

	return p1.y < p2.y;
}

int calculateDistance(Point p1, Point p2) {

	return p2.y - p1.y;
}

int maxWidth(Point *posts, int n) {

	sort(posts, posts+n, compare);

	int *distance = new int[n+1];

	Point prev;
	prev.x = 0;
	prev.y = 0;

	for(int i = 0; i < n; i++) {
		distance[i] = calculateDistance(prev, posts[i]);
		prev = posts[i];
	}

	Point end;
	end.x = 1;
	end.y = 200;

	distance[n] = calculateDistance(prev, end);

	int width = distance[0];
	for(int i = 1; i <= n; i++) {
		width = max(width, distance[i]);
	}

	delete [] distance;

	return width-1;
}

int main() {

	int n;
	cin >> n;

	Point *posts = new Point[n];

	for(int i = 0; i < n; i++) {
		cin >> posts[i].x;
	}
	for(int i = 0; i < n; i++) {
		cin >> posts[i].y;
	}

	int ans = maxWidth(posts, n);

	cout << ans << endl;

	delete [] posts;

	return 0;
}