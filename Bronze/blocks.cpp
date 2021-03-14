/*
ID: swarnya1
TASK: blocks
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz"
	vector<string> front;
	vector<string> back;

	vector<int> count;
	vector<int> one_count; // >:)

	int n;
	string temp;
	std::size_t found;

	ifstream fin("blocks.in");
	ofstream fout("blocks.out");

	fin >> n;

	for (int i = 0; i < n; i++) {
		fin >> temp;
		front.push_back(temp);
		fin >> temp;
		back.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		// init onecount to 0
		for (int k = 0; k < front[i].length(); k++) {
			found = str.find(front[i][k]);
			one_count[]
		}
		for (int j = i + 1; j < n; j++) {
			// front[i] vs back[j]
			for (int k = 0; k < back[j].length(); k++)
		}
		// compare one count to count
	}
	// repeat


	for (int i = 0; i < 26; i++) {
		fout << count[i] << endl;
	}

	fout.close();
	return 0;
}