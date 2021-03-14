/*
ID: swarnya1
TASK: tttt
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
	vector<long long> x;
	vector<long long> y;
	long long n;
	long long temp;
	long long tempa;
	long long max_area = 0;

	ifstream fin("triangles.in");
	ofstream fout("triangles.out");

	fin >> n;

	for (long long i = 0; i < n; i++) {
		fin >> temp;
		x.push_back(temp);
		fin >> temp;
		y.push_back(temp);
	}

	for (long long i = 0; i < n; i++) {
		for (long long l = 0; l < n; l++) {
			for (long long h = 0; h < n; h++) {
			    // cout << i << " " << h << " " << l << endl;
				if (l != i && h != i) {
					if (x[l] == x[i] && y[h] == y[i]) {
						tempa = (abs(x[i] - x[h])*abs(y[i] - y[l]));
						// cout << i << " " << h << " " << l << " " << tempa << endl;
						if (tempa > max_area)
							max_area = tempa;
					}
				}
			}
		}
	}
    
    fout << max_area << endl;
	fout.close();
	return 0;
}