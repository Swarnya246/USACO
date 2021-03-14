#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("candy.out");
    ifstream fin("candy.in");
    
    int n;
    int stack;
    int total = 0;
    
    fin >> n;
    
    for (int i = 0; i < n; i++) {
        fin >> stack;
        total += stack;
    }
    
    for (int i = 2; i <= total; i++) {
        if (total % i == 0) {
            fout << i << " " << total/i << endl;
            return 0;
        }
    }
    
    return 0;
}