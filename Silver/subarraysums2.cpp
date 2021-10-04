#include <bits/stdc++.h>
using namespace std;

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/

    int n, x;
    cin >> n >> x;

    vector<int> v(n + 2);

    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        v[i] = v[i - 1] + temp;
    }

    int count = 0;

    int i = 0;
    int j = 0;
    while (j <= n && i <= j) {
        if (v[j] - v[i] == x)
            count++;

        if (v[j + 1] - v[i] <= x) {
            j++;
        } else {
            i++;
        }
    }

    cout << count << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output
*/