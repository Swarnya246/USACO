#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.first < b.first);
}

int main() {
	ifstream fin;
    ofstream fout;
    fin.open("pairup.in");
    fout.open("pairup.out");
    
    int n;
    fin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end(), compare);

    int max = 0;
    int left = 0; int i = 0;
    int right = n - 1; int j = 0;
    while (left <= right) {
        // cout << v[left].first << " " << v[right].first << endl;
        i++;
        j++;

        if (v[left].first + v[right].first > max) {
            max = v[left].first + v[right].first;
        }

        if (i >= v[left].second) {
            left++;
            i = 0;
        }
        if (j >= v[right].second) {
            right--;
            j = 0;
        }
    }

    fout << max << endl;

	return 0;
}

/*
3
2 8
2 5
2 2

g++ -o output template.cpp
./output
*/