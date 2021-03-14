/*
ID: swarnya1
TASK: cowsignal
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	int m;
	int n;
	int k;
	string temp;
	vector<string> signal;

	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");
	
	fin >> m >> n >> k;
	
	for (int i = 0; i < m; i++) {
		fin >> temp;
		signal.push_back(temp);
	}

	fin.close();

	for (int i = 0; i < m; i++) {
		temp = "";
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < k; l++) {
				temp += signal[i][j];
			}
		}
		for (int l = 0; l < k; l++) {
			fout << temp << endl;
		}
	}

	fout.close();
	return 0;
}