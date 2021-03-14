/*
ID: swarnya1
TASK: shuffle
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool compare(vector<int> i, vector<int> j) {
	return (i[0] < j[0]);
}

int main()
{
	vector<vector<int>> cows;
	vector<int> bovine;
	int n;
	int temp;
    
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");

	fin >> n;
	
	for (int i = 0; i < n; i++) {
		fin >> temp;
		cows.push_back({temp, 0});
		bovine.push_back(temp);
		//cows[i][0] = temp;
		// nums
	}
    
	for (int i = 0; i < n; i++) {
		fin >> temp;
		cows[i][1] = temp;
		// ids
	}
    
    sort(cows.begin(), cows.end(), compare);
    
    for (int i = 0; i < n; i++) {
		cows[i][0] = bovine[i];
	}
    
    sort(cows.begin(), cows.end(), compare);

    for (int i = 0; i < n; i++) {
		cows[i][0] = bovine[i];
	}
    
    sort(cows.begin(), cows.end(), compare);

    for (int i = 0; i < n; i++) {
		cows[i][0] = bovine[i];
	}

	for (int i = 0; i < n; i++) {
		fout << cows[i][1] << endl;
	}
	//fout.close();
	return 0;
}