
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("pile.out");
    ifstream fin("pile.in");
    
    string screws;
    string special;
    
    fin >> screws;
    fin >> special;

    int n = screws.length();
    int s = special.length();
    int k;
    int p;
    string collected;
    int min = n;

    for (int i = s; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            k = 0;
            p = 0;
            collected = "";

            while (k < i) {
                collected += screws[j + k];
                k++;
            }

            for (int m = 0; m < special.length(); m++) {
                if (collected.find(special[m]) != std::string::npos) {
                    p++;
                }
            }
            
            if (p == s) {
                fout << i << endl;
                return 0;
            }
        }
    }
    
    fout << n << endl;
    
    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("pile.out");
    ifstream fin("pile.in");
    
    string screws;
    string special;
    
    fin >> screws;
    fin >> special;

    int n = screws.length();
    int s = special.length();
    int k;
    int p;
    string collected;
    std::size_t found;
    int min = n;

    for (int i = s; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            k = 0; 
            p = 0; // number of special screws found
            collected = "";
            while (k < i) {
                collected += screws[j + k];
                k++;
            }
            
            for (int m = 0; m < special.length(); m++) {
                found = collected.find(special[m]);
                if (found != std::string::npos) {
                    p++;
                    collected.erase(collected.begin()+found);
                }
            }
            
            if (p == s) {
                fout << i << endl;
                return 0;
            }
        }
    }
    
    fout << n << endl;
    
    return 0;
}
*/