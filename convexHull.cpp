#include<bits/stdc++.h>
using namespace std;

class Point {
	public :
		int x;
		int y;
};

bool toChange(Point p, Point q, Point r) {

	int x1 = q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;

	int crossProduct = (x1*y2) - (y1*x2);

	return crossProduct < 0;
}

void convexHull(Point *points, int n) {

	int left = 0;
	for(int i = 1; i < n; i++) {
		if(points[i].x < points[left].x) {
			left = i;
		}
	}

	vector<Point> hull;
	int p = left;

	do {

		hull.push_back(points[p]);

		int q = (p+1)%n;

		for(int i = 0; i < n; i++) {
			if(toChange(points[p], points[q], points[i])) {
				q = i;
			}
		}

		p = q;

	} while(p != left);

	for(int i = 0; i < hull.size(); i++) {
		cout << hull[i].x << " " << hull[i].y << endl;
	}
}

int main() {

	int n;
	cin >> n;

	Point *points = new Point[n];

	for(int i = 0; i < n; i++) {
		cin >> points[i].x;
	}
	for(int i = 0; i < n; i++) {
		cin >> points[i].y;
	}

	convexHull(points, n);

	delete [] points;

	return 0;
}