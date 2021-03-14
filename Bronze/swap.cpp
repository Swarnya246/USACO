/*
ID: swarnya1
TASK: swap
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	int a1;
	int a2;
	int b1; 
	int b2;
	int temp;

	ifstream fin("swap.in");
	ofstream fout("swap.out");
	
	fin >> n >> k >> a1 >> a2 >> b1 >> b2;
	a1--; b1--;
	fin.close();

	vector<int> cows;
	for (int i = 0; i < n; i++) {
		cows.push_back(i+1);
	}
	
	for (int i = 0; i < k; i++) {
		/*for (int j = a1; j < a1 + (a2 - a1)/2 + 1; j++) {
			temp = cows[j];
			cows[j] = cows[a2 - j + a1];
			cows[a2 - j + a1] = temp;
			
			for (int h = 0; h < n; h++) {
			    cout << cows[h] << " ";
			}
			cout << endl;
		}
		for (int j = b1; j < b1 + (b2 - b1)/2 + 1; j++) {
			temp = cows[j];
			cows[j] = cows[b2 - j + b1];
			cows[b2 - j + b1] = temp;
			
			for (int h = 0; h < n; h++) {
			    cout << cows[h] << " ";
			}
			cout << endl;
		}*/
		reverse(cows.begin() + a1, cows.begin() + a2);
	    reverse(cows.begin() + b1, cows.begin() + b2);
	}

	for (int i = 0; i < n; i++) {
		fout << cows[i] << endl;
	}

	fout.close();
	return 0;
}