#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	double xCord;
	double yCord;
public:
	point(double x, double y) {
		xCord = x;
		yCord = y;
	}
	double returnX() {
		return xCord;
	}
	double returnY() {
		return yCord;
	}
	void display() {
		cout << xCord << " " << yCord << endl;
	}
};

vector<point> points;
int numPoints, radius;
double ansx, ansy, mostp;

int countPoints(double x, double y) {
	int ret = 0;
	for (int i = 0; i < numPoints; ++i) {
		if (sqrt(pow(points.at(i).returnY() - y, 2) + pow(points.at(i).returnX() - x, 2)) <= radius) {
			ret++;
		}
	}
	return ret;
}

int main() {
	ansx = 0;
	ansy = 0;
	mostp = 0;
	cin >> numPoints;
	for (int i = 0; i < numPoints; ++i) {
		double x, y;
		cin >> x >> y;
		point p1(x, y);
		points.push_back(p1);
	}
	cin >> radius;
	for (int x = 0; x < numPoints; ++x) {
		for (int y = (x + 1); y < numPoints; ++y) {
			if (sqrt(pow(points.at(x).returnY() - points.at(y).returnY(), 2) + pow(points.at(x).returnX() - points.at(y).returnX(), 2)) <= radius * 2) {
				cout << "valid (" << x << ", " << y << ")";
				int p = countPoints((points.at(x).returnX() + points.at(y).returnX()) / 2, (points.at(x).returnY() + points.at(y).returnY()) / 2);
				if (mostp < p) {
					ansx = (points.at(x).returnX() + points.at(y).returnX()) / 2;
					ansy = (points.at(x).returnY() + points.at(y).returnY()) / 2;
					mostp = p;
				}
			}
		}
	}
	cout << "Center: " << ansx << ", " << ansy << "\nMax Points: " << mostp << endl;
}
