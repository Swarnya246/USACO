#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin;
    ofstream fout;
    fin.open("diamond.in");
    fout.open("diamond.out");
    
    int n, k;
    fin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> canTakeLeft(n);
    int l = 0;
    int r = 0;
    for (; l < n; l++) {
        while (r < n && v[r] - v[l] <= k) r++;
        canTakeLeft[l] = r - l;
    }

    vector<int> maxValueAfterI(n);
    for (int i = n - 1; i >= 0; i--) {
        maxValueAfterI[i] = max(canTakeLeft[i], maxValueAfterI[i + 1]);
    }

    int maximum = 0;
    for (int i = 0; i < n; i++) {
        maximum = max(maximum, canTakeLeft[i] + maxValueAfterI[i + canTakeLeft[i]]);
    }

    fout << maximum << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output
*/