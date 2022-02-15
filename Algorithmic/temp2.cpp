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
	int points[100][2] = { 0 };
	for (int i = 0; i < 100; ++i) {
		int seed = rand() % 10;
		if (seed < 5) {
			int x = rand() % 15 + 35;
			int y = rand() % 25 + 35;
			points[i][1] = x;
			points[i][2] = y;
			cout << "(" << x << "," << y << "), ";
		}
		else if (seed < 9) {
			int x = rand() % 30 + 1;
			int y = rand() % 30 + 1;
			points[i][1] = x;
			points[i][2] = y;
			cout << "(" << x << "," << y << "), ";
		}
		else {
			int x = rand() % 100 + 1;
			int y = rand() % 100 + 1;
			points[i][1] = x;
			points[i][2] = y;
			cout << "(" << x << "," << y << "), ";
		}
	}
	cout << "\n\n" << endl;
	for (int i = 0; i < 100; ++i) {
		cout << points[i][0] << " " << points[i][2] << endl;
	}
}
