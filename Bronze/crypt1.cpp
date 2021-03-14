/*
ID: swarnya1
TASK: crypt1
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");

	int n;
	int digit;
	vector<int> digits;
	bool isSolution = true;
	int solutions = 0;
	int num1;
	int num2;
	int x;
	string prod1;
	string prod2;
	string product;
	bool isSub = false;
	bool isSub1 = false;
	bool isSub2 = false;

	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> digit;
		digits.push_back(digit);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int m = 0; m < n; m++) {
					for (int q = 0; q < n; q++) {
						isSolution = true;

						num1 = stoi(to_string(digits[i]) + to_string(digits[j]) + to_string(digits[k]));
						num2 = stoi(to_string(digits[m]) + to_string(digits[q]));

						prod1 = to_string(num1 * digits[m]);
						prod2 = to_string(num1 * digits[q]);

						if (prod1.length() > 3 || prod2.length() > 3)
							isSolution = false;

						for (int o = 0; o < 3; o++) {
							isSub1 = false;
							isSub2 = false;
							for (int p = 0; p < n; p++) {
								x = prod1[o] - '0';
								if (x == digits[p]) {
									isSub1 = true;
								}
								x = prod2[o] - '0';
								if (x == digits[p]) {
									isSub2 = true;
								}
							}
							if (!isSub1 || !isSub2)
								isSolution = false;
						}

						product = to_string(stoi(prod2) * 10 + stoi(prod1));

						if (product.length() > 4)
							isSolution = false;

						for (int o = 0; o < 4; o++) {
							isSub = false;
							for (int p = 0; p < n; p++) {
								if (!isSolution)
									break;
								x = product[o] - '0';
								if (x == digits[p]) {
									isSub = true;
								}
							}
							if (!isSub)
								isSolution = false;
						}

						if (isSolution) {
							solutions++;
							// cout << num1 << " " << num2 << " " << prod1 << " " << prod2 << " " << product << endl;
						}

						//cout << num1 << " " << num2 << " " << prod1 << " " << prod2 << " " << product << endl;
					}
				}
			}
		}
	}

	fout << solutions << endl;
	// compute solutions

	// output solutions

	return 0;
}