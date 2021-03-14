/*
ID: swarnya1
TASK: speeding
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	vector<int> road;
	vector<int> bessie;

	int n;
	int m;
    int mile;
    int limit;

    int max = 0;

	ifstream fin("speeding.in");
	ofstream fout("speeding.out");

	fin >> n;
	fin >> m;

	int nstart = 0;
	int mstart = 0;
	
	for (int i = 0; i < n; i++) {
		fin >> mile;
		fin >> limit;
		for (int j = nstart; j < mile; j++) {
			road.push_back(limit);
		}
	}

	for (int i = 0; i < m; i++) {
		fin >> mile;
		fin >> limit;
		for (int j = mstart; j < mile; j++) {
			bessie.push_back(limit);
		}
	}

	for (int i = 0; i < 100; i++) {
		if (bessie[i] - road[i] > max)
			max = bessie[i] - road[i];
	}
	
	fout << max << endl;

	fout.close();
	return 0;
}