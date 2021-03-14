#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("grandprix.out");
    ifstream fin("grandprix.in");
    
    int n;
    int power;
    int target;
    vector<int> horses;
    
    fin >> n;
    fin >> target;
    
    for (int i = 0; i < n; i++) {
        fin >> power;
        horses.push_back(power);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (horses[i] + horses[j] == target) {
                fout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    
    return 0;
}