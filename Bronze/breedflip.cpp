/*
ID: swarnya1
TASK: breedflip
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int min = 0;
	string a;
	string b;
	int n;
	int temp;
	bool streak = false;

	ifstream fin("breedflip.in");
	ofstream fout("breedflip.out");

	fin >> n;

	for (int i = 0; i < 2; i++) {
		fin >> a;
		fin >> b;
	}
	
	for (int i = 0; i < n; i++) {
		if (streak) {
			if (a[i] == b[i]) {
				streak = false;
			}
		} else {
			if (a[i] != b[i]) {
				streak = true;
				min++;
			}
		}
		
	}

    fout << min << endl;
	fout.close();
	return 0;
}