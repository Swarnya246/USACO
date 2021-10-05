#include <bits/stdc++.h>
using namespace std;

struct s {
    int index;
    int value;
};

bool compare(s a, s b) {
    return (a.value < b.value);
}

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/

    int n, x;
    cin >> n >> x;

    if (n < 3) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<s> v(n);
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i].index = i + 1;
        v[i].value = temp;
    }

    sort(v.begin(), v.end(), compare);
/*
    for (int i = 0; i < n; i++) {
        cout << v[i].value << " ";
    }
    cout << endl;
*/
    int i, j;
    for (int k = 0; k < n; k++) {
        i = 0;
        j = n - 1;

        while (i < j) {
            if ((v[i].value + v[j].value + v[k].value == x) && ((i != k && j != k) && i != j)) {
                cout << v[i].index << " " << v[j].index << " " << v[k].index << endl;
                return 0;
            }

            //cout << i << " " << j << " " << k << endl;
            if (v[i].value + v[j].value + v[k].value < x) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output
*/