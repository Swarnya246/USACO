#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin;
    ofstream fout;
    fin.open("lazy.in");
    fout.open("lazy.out");

	int n, k;
	fin >> n >> k;
	vector<vector<int>> grass(n + 2 * k + 1, vector<int>(n + 2 * k + 1, 0));

	int temp;
	for (int i = k + 1; i <= n + k; i++) {
		for (int j = k + 1; j <= n + k; j++) {
			fin >> temp;
			grass[i][j] = grass[i][j - 1] + temp;
		}
	}
/*
	for (int i = 0; i <= n + 2 * k; i++) {
		for (int j = 0; j <= n + 2 * k; j++) {
			cout << grass[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
*/
	int max = 0;
	for (int i = k + 1; i <= n + k; i++) {
		for (int j = k + 1; j <= n + k; j++) {
			temp = 0;
			for (int m = 0; m <= k; m++) {
				temp += grass[i + k - m][j + m] - grass[i + k - m][j - m - 1];
				temp += grass[i - k + m][j + m] - grass[i - k + m][j - m - 1];
			}
			temp -= grass[i][j + k] - grass[i][j - k - 1];
			if (temp > max)
				max = temp;
			// cout << temp << " ";
		}
		// cout << endl;
	}	

	fout << max << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output

5 2
50 5 25 6 17
14 3 2 7 21
99 10 1 2 80
8 7 5 23 11
10 0 78 1 9
*/