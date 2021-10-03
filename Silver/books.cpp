#include <bits/stdc++.h>
using namespace std;

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/

    int n, t;
    cin >> n >> t;

    vector<int> books(n + 2, 0);

    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        books[i] = temp + books[i - 1];
    }

    int left = 0;
    int right = 0;
    int max = 0;
    int minutes = 0;

    while (left <= n && right <= n) {
        // cout << left << " " << right << " " << books[right] - books[left] << endl;
        if (right - left > max)
            max = right - left;

        if (books[right + 1] - books[left] <= t) {
            right++;
        } else {
            left++;
        }
    }

    cout << max << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output
*/