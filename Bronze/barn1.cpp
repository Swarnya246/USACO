/*
ID: swarnya1
TASK: barn1
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");

    int m;
    fin >> m;
    int s;
    fin >> s;
    int c;
    fin >> c;

    int streaks = 0;
    bool streak = true;
    int temp;
    int covered;
    int last_stall = -1;
    int index_of_first_true = 0;
    vector<bool> cows_in_stall;
    vector<int> gaps;

    for (int i = 0; i < s; i++) {
        cows_in_stall.push_back(false);
    }

    for (int i = 0; i < c; i++) {
        fin >> temp;
        cows_in_stall[temp - 1] = true;
        if (i == 0) {
            index_of_first_true = temp - 1;
        }
    }
    if (cows_in_stall[0]) {
        last_stall = 0;
        streaks++;
    }
    for (int i = 1; i < s; i++) {
        if (cows_in_stall[i] && !cows_in_stall[i - 1]) {
            streak = true;
            streaks++;
            if (last_stall != -1) {
                gaps.push_back(i - last_stall);
            }
        }
        else if (!cows_in_stall[i] && cows_in_stall[i - 1]) {
            streak = false;
            last_stall = i;
        }
    }

    sort(gaps.begin(), gaps.end());
    covered = c;

    if (streaks <= m) {
        fout << covered << endl;
    }
    else {
        int i = 0;
        while (streaks > m && i < gaps.size()) {
            streaks--;
            covered += gaps[i];
            i++;
        }
        fout << covered << endl;
    }

    return 0;
}

/*
if the number of streaks <= m,
    cout c
else
    bridge the smallest gaps and cout the number of stalls covered
*/