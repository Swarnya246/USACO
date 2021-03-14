/*
ID: swarnya1
TASK: shell
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	int n;
	int temp;
	int score;
	bool btemp;

	int max_score = 0;

	vector<int> a;
	vector<int> b;
	vector<int> g;
	vector<int> shells;

	for (int i = 0; i < 2; i++) {
		shells.push_back(false);
	}

	ifstream fin("shell.in");
	ofstream fout("shell.out");

	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> temp;
		a.push_back(temp);
		fin >> temp;
		b.push_back(temp);
		fin >> temp;
		g.push_back(temp);
	}
	
	for (int i = 0; i < 3; i++) {
		shells[i] = true;
		score = 0;

		for (int j = 0; j < n; j++) {
			btemp = shells[a[j]];
			shells[a[j]] = shells[b[j]];
			shells[b[j]] = btemp;
			if (shells[g[j]])
				score++;
		}

		if (score > max_score)
			max_score = score;
		
		for (int i = 0; i < 2; i++) {
			shells[i] = false;
		}
	}

	fout << max_score << endl;

	fout.close();
	return 0;
}