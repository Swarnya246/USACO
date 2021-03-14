/*
ID: swarnya1
TASK: skidesign
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	int hill;
	int square = 0;
	int cost = 0;
	int final_cost = 0;
	vector<int> hills;
	int max = 0;
	int min = 0;
	ifstream fin("skidesign.in");
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> hill;
		hills.push_back(hill);
	}
	fin.close();

	for (int j = 0; j < n; j++) {
		for (int k = j + 1; k < n; k++) {
			cost = 0;
			if (hills[j] > hills[k]) {
				max = hills[j];
				min = hills[k];
			}
			else {
				min = hills[j];
				max = hills[k];
			}

			if (max - min > 17) {
				for (int i = 0; i < (max - min - 17); i++) {
					square = pow(i, 2) + pow(max - min - 17 - i, 2);
					if (i == 0)
					    cost = square;

					if (square < cost) {
						if (hills[j] > hills[k]) {
							hills[j] -= max - min - 17 - i;
							hills[k] += i;
						}
						else {
							hills[j] += i;
							hills[k] -= max - min - 17 - i;
						}
					}
				}
				final_cost += cost;
			}
		}
	}

	ofstream fout("skidesign.out");
	fout << final_cost << endl;
	fout.close();
	return 0;
}

/*
you're given a difference, and you need to get to the number 17 in a way that the squares of tbe differences are minimized
*/