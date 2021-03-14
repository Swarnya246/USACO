/*
ID: swarnya1
TASK: mixmilk
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	int temp;
	vector<int> capacity;
	vector<int> bucket;

	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

	for (int i = 0; i < 3; i++) {
		fin >> temp;
		capacity.push_back(temp);
		fin >> temp;
		bucket.push_back(temp);
	}
	
	for (int i = 0; i < 100; i++) {
		if (bucket[0] <= capacity[1] - bucket[1]) {
			bucket[1] += bucket[0];
			bucket[0] = 0;
		} 
		else if (capacity[1] - bucket[1] > 0) {
		    bucket[0] -= capacity[1] - bucket[1];
			bucket[1] = capacity[1];
		}
		if (bucket[1] <= capacity[2] - bucket[2]) {
			bucket[2] += bucket[1];
			bucket[1] = 0;
		} 
		else if (capacity[2] - bucket[2] > 0) {
			bucket[1] -= capacity[2] - bucket[2];
			bucket[2] = capacity[2];
		}
		if (bucket[2] <= capacity[0] - bucket[0]) {
			bucket[0] += bucket[2];
			bucket[2] = 0;
		} 
		else if (capacity[0] - bucket[0] > 0) {
			bucket[2] -= capacity[0] - bucket[0];
			bucket[0] = capacity[0];
		}
	}
	
    if (bucket[0] <= capacity[1] - bucket[1]) {
		bucket[1] += bucket[0];
		bucket[0] = 0;
	} 
	else if (capacity[1] - bucket[1] > 0) {
	    bucket[0] -= capacity[1] - bucket[1];
		bucket[1] = capacity[1];
	}
		
	for (int i = 0; i < 3; i++) {
		fout << bucket[i] << endl;
	}

	fout.close();
	return 0;
}