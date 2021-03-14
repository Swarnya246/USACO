#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int n;
    fin >> n;

    //int numcows[n];
    int nummilk[n];
    int cows = 0;

    for (int i = 0; i < n; i++) {
        fin >>  >> nummilk[i];
    }

    sort(nummilk, nummilk+n)
    
    fout << nummilk[0] + nummilk[n-1] << endl;

    return 0;
}