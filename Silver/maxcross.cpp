#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
 
    ifstream fin;
    ofstream fout;
    fin.open("maxcross.in");
    fout.open("maxcross.out");

    int n, k, b;
    fin >> n >> k >> b;
    
    int temp;
    vector<int> pref(n + 1, 0);
    int min = b;
    
    for (int i = 0; i < b; i++) {
        fin >> temp;
        pref[temp]++;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
        // cout << pref[i] << " ";
        if (i >= k) {
            // cout << pref[i] - pref[i - k] << endl;
            if (pref[i] - pref[i - k] < min) {
                min = pref[i] - pref[i - k];
            }
        }
    }

    fout << min << endl;

    return 0;
}