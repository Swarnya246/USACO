#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("hps.in");
    fout.open("hps.out");

    int n;
    fin >> n;
    
    char temp;
    vector<vector<int>> pref(3, vector<int>(n + 1, 0));
    pref[0][0] = 0; pref[1][0] = 0; pref[2][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        fin >> temp;
        if (temp == 'H') { pref[0][i]++; }
        if (temp == 'P') { pref[1][i]++; } 
        if (temp == 'S') { pref[2][i]++; } 
        for (int j = 0; j < 3; j++) {
            pref[j][i] += pref[j][i - 1];
        }
    }

    int max = 0;
    int combo;

    for (int i = 0; i <= n; i++) {
        combo = pref[0][i] + pref[1][n] - pref[1][i];
        if (combo > max)
            max = combo;

        combo = pref[1][i] + pref[0][n] - pref[0][i];
        if (combo > max)
            max = combo;

        combo = pref[0][i] + pref[2][n] - pref[2][i];
        if (combo > max)
            max = combo;

        combo = pref[2][i] + pref[0][n] - pref[0][i];
        if (combo > max)
            max = combo;

        combo = pref[1][i] + pref[2][n] - pref[2][i];
        if (combo > max)
            max = combo;

        combo = pref[2][i] + pref[1][n] - pref[1][i];
        if (combo > max)
            max = combo;

        /*
        for (int j = 0; j < 3; j++) {
            cout << pref[j][i] << " ";
        }
        cout << endl;
        */
    }

    if (pref[0][n] > max)
        max = pref[0][n];
    if (pref[1][n] >  max)
        max = pref[1][n];
    if (pref[2][n] > max)
        max = pref[2][n];

    fout << max << endl;

    fin.close();
    fout.close();

    return 0;
}