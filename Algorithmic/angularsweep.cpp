#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int xCord;
	int yCord;
public: 
	point(int x, int y) {
		xCord = x;
		yCord = y;
	}
	int returnX() {
		return xCord;
	}
	int returnY() {
		return yCord;
	}
	void setX(int x) {
		xCord = x;
	}
	void setY(int y) {
		yCord = y;
	}
	void display() {
		cout <<  xCord << " " << yCord << endl;
	}
};

int main() {
	vector<point> points;
	vector<int> radii;
	vector<point> answers;
	int arr1[50] = { 0 };
	int numPoints, numCircles;
	cin >> numPoints; 
	for (int i = 0; i < numPoints; ++i) {
		int x, y;
		cin >> x >> y;
		point p1(x, y);
		points.push_back(p1);
	}
	cin >> numCircles;
	for (int i = 0; i < numCircles; ++i) {
		int x;
		cin >> x;
		arr1[i] = x;
		radii.push_back(x);
	}
	sort(radii.begin(), radii.end(), greater<int>());
	for (int radNum = 0; radNum < radii.size(); ++radNum) {
		int maxpp = 0;
		int retX = points.at(0).returnX();
		int retY = points.at(0).returnY();

		for (int firstP = 0; firstP < points.size(); ++firstP) {
			for (int secondP = 0; secondP < points.size(); ++secondP) {
				if (secondP != firstP) {
					double q = sqrt(pow((points.at(firstP).returnX() - points.at(secondP).returnX()), 2) + pow((points.at(firstP).returnY() - points.at(secondP).returnY()), 2));
					double y3 = (points.at(firstP).returnY() + points.at(secondP).returnY()) / 2;
					double x3 = (points.at(firstP).returnX() + points.at(secondP).returnX()) / 2;
					int circleNum = 0;
					double centerX = 0;
					double centerY = 0;
					if (q > (double)(2 * radii.at(radNum))) {
						break;
					}
					if (q == (double)(2 * radii.at(radNum))) {
						circleNum = 1;
						centerX = x3;
						centerY = y3;
					}
					else if (q < (double)(2 * radii.at(radNum))) {
						circleNum = 2;
						centerX = x3 + sqrt(pow(radii.at(radNum), 2) - pow(q / 2, 2)) * (points.at(firstP).returnY() - points.at(secondP).returnY()) / q;
						centerY = y3 + sqrt(pow(radii.at(radNum), 2) - pow(q / 2, 2)) * (points.at(secondP).returnX() - points.at(firstP).returnX()) / q;
					}
					for (int p = 0; p < circleNum; ++p) {
						int ppnum = 0;
						for (int i = 0; i < points.size(); ++i) {
							if (i != firstP && i != secondP) {
								int d = sqrt(pow((centerX - points.at(i).returnX()), 2) + pow((centerY - points.at(i).returnY()), 2));
								if (d < radii.at(radNum)) {
									++ppnum;
								}
							}
						}
						if (ppnum > maxpp) {
							maxpp = ppnum;
							retX = centerX;
							retY = centerY;
						}
						if (p == 1) {
							centerX = x3 - sqrt(pow(radii.at(radNum), 2) - pow(q / 2, 2)) * (points.at(firstP).returnY() - points.at(secondP).returnY()) / q;
							centerY = y3 - sqrt(pow(radii.at(radNum), 2) - pow(q / 2, 2)) * (points.at(secondP).returnX() - points.at(firstP).returnX()) / q;
						}
					}
				}
			}
		}
		point p2(retX, retY);
		answers.push_back(p2);
		cout << "\nanswer found at: (" << retX << ", " << retY << ")\n" << endl; 
		for (int i = 0; i < points.size(); ++i) {
			int d = sqrt(pow((retX - points.at(i).returnX()), 2) + pow((retY - points.at(i).returnY()), 2));
			if (d < radii.at(radNum)) {
				auto k = points.begin() + i;
				points.erase(k);
			}
		}
	}
	vector<point> realans;
	for (int i = 0; i < numCircles; ++i) {
		for (int k = 0; k < numCircles; ++k) {
			if (arr1[i] == radii.at(k)) {
				realans.push_back(answers.at(k));
				auto b = radii.begin() + k;
				radii.erase(b);
				auto c = answers.begin() + k;
				answers.erase(c);
				break;
			}
		}
	}
	for (int i = 0; i < realans.size(); ++i) {
		realans.at(i).display();
	}
	//remove system("pause"); if program is directly submitted to an auto grader
	system("pause");
}
