#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
// vector<vector<int>> test
// map<int, int> test2
// test2.insert(pair<int, int> (30, 70));

class graph {
public:
	int numCities;
	int numEdges;
	vector<pair<pair<int, int>, pair<int, int>>> connectedCities; 
	void init() {
		numCities = 2;
		numEdges = 1;
	}
	void addCity() {
		numCities++;
	}
	void addEdges() {
		numEdges++;
	}
	void addGraph(graph test) {
		numCities += test.numCities;
		numEdges += test.numEdges + 1;
	}
	void del() {
		numCities = 0;
		numEdges = 0;
	}
private:
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<graph> graphs;
	for (int i = 0; i < m; ++i) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		pair<int, int> cit1;
		cit1.first = x;
		cit1.second = y;
		pair<int, int> cit2;
		cit2.first = x1;
		cit2.second = y1;
		graph nig;
		nig.init();
		nig.connectedCities.push_back(pair<pair<int, int>, pair<int, int>>(cit1, cit2));
		graphs.push_back(nig);

		// see if new flight connects two different graphs

		for (int i = 0; i < graphs.size() - 1; ++i) {
			int conNum = 0;
			for (int k = 0; k < graphs[i].connectedCities.size(); ++k) {
				bool ff = (graphs[i].connectedCities[k].first.first == cit1.first) && (graphs[i].connectedCities[k].first.second == cit1.second);
				bool ss = (graphs[i].connectedCities[k].second.first == cit2.first) && (graphs[i].connectedCities[k].second.second == cit2.second);
				bool fs = (graphs[i].connectedCities[k].first.first == cit2.first) && (graphs[i].connectedCities[k].first.second == cit2.second);
				bool sf = (graphs[i].connectedCities[k].second.first == cit1.first) && (graphs[i].connectedCities[k].second.second == cit1.second);
				if (ff || ss || fs || sf) {
					conNum++;
					break;
				}
				if (conNum == 2) {
					break;
				}
			}
			if (conNum == 1) {
				graphs.erase(graphs.end() - 1);
				graphs[i].addEdges();
				graphs[i].addCity();
				graphs[i].connectedCities.push_back(pair<pair<int, int>, pair<int, int>>(cit1, cit2));
				break;
			}
			else if (conNum == 2) {
				graphs.erase(graphs.end() - 1);
				graphs[i].addEdges();
				graphs[i].connectedCities.push_back(pair<pair<int, int>, pair<int, int>>(cit1, cit2));
				break;
			}
		}
	}
	int out = pow(n, 2);
	for (int i = 0; i < graphs.size(); ++i) {
		out += (graphs[i].numCities - 1) * graphs[i].numCities;
	}
	cout << out << endl;
	//system("pause");
}
