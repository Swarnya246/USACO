#include <bits/stdc++.h>
using namespace std;

struct point {
    int index;
    int value;
};

bool compare(point a, point b)
{
    return (a.value < b.value);
}

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/
    int n, target;
    cin >> n >> target;

    vector<point> v(n);
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i].index = i;
        v[i].value = temp;
    }

    sort(v.begin(), v.end(), compare);

    int a = 0;
    int b = n - 1;
    for (int i = 0; i < n; i++) {
        if (v[a].value + v[b].value > target && b > a + 1) {
            b--;
        }
        if (v[a].value + v[b].value < target && a < b - 1) {
            a++;
        }
        if (v[a].value + v[b].value == target && v[a].index != v[b].index) {
            cout << min(v[a].index, v[b].index) + 1 << " " << max(v[a].index, v[b].index) + 1 << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
	return 0;
}

/*
g++ -o output template.cpp
./output
*/