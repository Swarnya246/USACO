/*
ID: swarnya1
TASK: combo
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");

	int n;
	int dial;
	int i;
	int j;
	int k;
	string combo;
	vector<int> john;
	vector<int> master;
	vector<string> solutions;

	fin >> n;
	for (int i = 0; i < 3; i++) {
		fin >> dial;
		john.push_back(dial);
	}

	for (int i = 0; i < 3; i++) {
		fin >> dial;
		master.push_back(dial);
	}

	for (int inum = john[0] - 2; inum < john[0] + 3; inum++) {
		for (int jnum = john[1] - 2; jnum < john[1] + 3; jnum++) {
			for (int knum = john[2] - 2; knum < john[2] + 3; knum++) {
				i = inum;
				j = jnum;
				k = knum;
				while (i < 1)
					i = n + i;
				while (i > n)
					i = i - n;
				while (j < 1)
					j = n + j;
				while (j > n)
					j = j - n;
				while (k < 1)
					k = n + k;
				while (k > n)
					k = k - n;

				combo = to_string(i) + to_string(j) + to_string(k);

				if (!(find(solutions.begin(), solutions.end(), combo) != solutions.end()))
				{
					solutions.push_back(combo);
				}
			}
		}
	}

	for (int inum = master[0] - 2; inum < master[0] + 3; inum++) {
		for (int jnum = master[1] - 2; jnum < master[1] + 3; jnum++) {
			for (int knum = master[2] - 2; knum < master[2] + 3; knum++) {
				i = inum;
				j = jnum;
				k = knum;
				while (i < 1)
					i = n + i;
				while (i > n)
					i = i - n;
				while (j < 1)
					j = n + j;
				while (j > n)
					j = j - n;
				while (k < 1)
					k = n + k;
				while (k > n)
					k = k - n;

				combo = to_string(i) + to_string(j) + to_string(k);

				if (!(find(solutions.begin(), solutions.end(), combo) != solutions.end()))
				{
					solutions.push_back(combo);
				}
			}
		}
	}

	fout << solutions.size() << endl;

	return 0;
}