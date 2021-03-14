#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    int n, q;
    fin >> n >> q;

    int cows[n + 1][3];
    cows[0][0] = 0;
    cows[0][1] = 0;
    cows[0][2] = 0;

    int temp;
    int a, b;

    for (int i = 1; i <= n; i++) {
        fin >> temp;
        cows[i][0] = cows[i - 1][0];
        cows[i][1] = cows[i - 1][1];
        cows[i][2] = cows[i - 1][2];
        if (temp == 1) {
            cows[i][0]++;
        } else if (temp == 2) {
            cows[i][1]++;
        } else if (temp == 3) {
            cows[i][2]++;
        }
    }

    for (int i = 0; i < q; i++) {
        fin >> a >> b;
        fout << cows[b][0] - cows[a - 1][0] << " " << cows[b][1] - cows[a - 1][1] << " " << cows[b][2] - cows[a - 1][2] << endl; 
    }

    return 0;
}