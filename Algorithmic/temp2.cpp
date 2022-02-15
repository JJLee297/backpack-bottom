#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdio.h>    
#include <stdlib.h>    
#include <time.h> 
using namespace std;

int main() {
	srand(time(NULL));
	int points[500][2] = { 0 };
	for (int i = 0; i < 500; ++i) {
		int seed = rand() % 10;
		if (seed < 2) {
			int x = rand() % 25 + 35;
			int y = rand() % 25 + 35;
			points[i][0] = x;
			points[i][1] = y;
			cout << "(" << x << "," << y << "), ";
		}
		else {
			int x = rand() % 100 + 1;
			int y = rand() % 100 + 1;
			points[i][0] = x;
			points[i][1] = y;
			cout << "(" << x << "," << y << "), ";
		}
	}
	cout << "\n\n" << endl;
	for (int i = 0; i < 500; ++i) {
		cout << points[i][0] << " " << points[i][1] << endl;
	}
}
