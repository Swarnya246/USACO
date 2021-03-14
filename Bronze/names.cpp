#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("names.out");
    ifstream fin("names.in");
    
    bool repeat = false;
    int n;
    int g;
    string str;
    vector<string> groupn;
    vector<string> groupg;
    vector<string> dups;
    fin >> n;
    fin >> g;
    
    for (int i = 0; i < n; i++) {
        fin >> str;
        groupn.push_back(str);
    }
    
    for (int i = 0; i < g; i++) {
        fin >> str;
        groupg.push_back(str);
    }
    
    sort(groupn.begin(), groupn.end());
    sort(groupg.begin(), groupg.end());
    
    if (n > g) {
        for (int i = 0; i < n; i++) {
            if (find(groupg.begin(), groupg.end(), groupn[i]) != groupg.end() && find(dups.begin(), dups.end(), groupn[i]) == dups.end()) {
                fout << groupn[i] << " ";
                dups.push_back(groupn[i]);
                repeat = true;
            }
        }    
    } else {
        for (int i = 0; i < g; i++) {
            if (find(groupn.begin(), groupn.end(), groupg[i]) != groupn.end() && find(dups.begin(), dups.end(), groupg[i]) == dups.end()) {
                fout << groupg[i] << " ";
                dups.push_back(groupg[i]);
                repeat = true;
            }
        }       
    }
    
    if (!repeat)
        fout << -1;
    
    return 0;
}