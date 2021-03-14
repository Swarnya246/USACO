/*
ID: swarnya1
TASK: word
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
	int k;
	int chars = 0;
	string word;

	ifstream fin("word.in");
	ofstream fout("word.out");
	
	fin >> n;
	fin >> k;
	
	for (int i = 0; i < n; i++) {
		fin >> word;
		if (word.length() + chars > k) {
			if (i != 0) {
				fout << endl;
			}
			chars = 0;
		} else {
		    if (i != 0) {
				fout << " ";
			}
		}
		fout << word;
		chars += word.length();
	}
	fin.close();

	fout.close();
	return 0;
}