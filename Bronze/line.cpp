#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("line.out");
    ifstream fin("line.in");
    
    int n;
    int horssie;
    int horse;
    bool behaving = true;
    vector<int> horses;
    
    fin >> n;
    fin >> horssie;
    
    for (int i = 0; i < n; i++) {
        fin >> horse;
        horses.push_back(horse);
    }
    
    vector<int>::iterator it;
    it = find(horses.begin(), horses.end(), horssie);

    if (it - horses.begin() > 0) {
        if (horses[it - horses.begin() - 1] > horssie)
            behaving = false;
    }
    
    if (it - horses.begin() < n - 1) {
        if (horses[it - horses.begin() + 1] < horssie)
            behaving = false;
    }
    
    if (behaving) {
        fout << it - horses.begin() << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (horses[i] > horssie) {
                fout << i << endl;
                return 0;
            }
        }   
        fout << n - 1 << endl;
    }
    
    return 0;
}