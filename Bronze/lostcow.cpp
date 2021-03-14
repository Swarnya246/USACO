/*
ID: swarnya1
TASK: lostcow
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	int step = 1;
	int total = 0;
	int x;
	int y;

	ifstream fin("lostcow.in");
	ofstream fout("lostcow.out");

	fin >> x;
	fin >> y;
    int current = x;
    bool found = (x < y && current > y) || (x > y && current < y);
    
    int i = 0;
	while (!(x < y && current > y) || (x > y && current < y)) {
		current = x + step;
		if ((x < y && current > y) || (x > y && current < y)) {
		    if (x > y)
		        total += x + step/(-2) - y;
		    else 
		        total += y - step/(-2) - x;
		}
        else
		    total += abs(x + step/(-2) - current);
    	step *= (-2);
        i++;
	}
	
	fout << total << endl;	

	fout.close();
	return 0;
}
