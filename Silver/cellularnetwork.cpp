#include <bits/stdc++.h>
using namespace std;

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/
    
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    vector<int> t(m);
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        c[i] = temp;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        t[i] = temp;
    }

    // find the index of the tower closest to the first city
    int max = abs(c[0] - t[0]);
    int index = 0;
    for (int i = 1; i < m; i++) {
        if (abs(c[0] - t[i]) < max) {
            max = abs(c[0] - t[i]);
            index = i;
        }
    }
    // find the distance from the closest tower for each city
    for (int i = 0; i < n; i++) {
        while ((index < m - 1) && (abs(c[i] - t[index]) >= abs(c[i] - t[index + 1]))) {
            index++;
        }
        if (abs(c[i] - t[index]) > max) {
            max = abs(c[i] - t[index]);
        }
        //cout << abs(c[i] - t[index]) << " ";
    }
    //cout << endl;
    cout << max << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output
*/