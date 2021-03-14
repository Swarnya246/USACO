/*
ID: swarnya1
TASK: namenum
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("namenum.out");
    ifstream fin;
    fin.open("namenum.in");
    string brand;
    fin >> brand;
    fin.close();
    int current = 0;
    vector<vector<char>> alphabet{ {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y'} };
    vector<string> solutions;
    vector<string> valid;
    bool aresol = false;
    string astringnum;

    fin.open("dict.txt");
    string astring;
    fin >> astring;
    while (fin) {
        string astringnum = "";
        for (int i = 0; i < astring.length(); i++) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 3; k++) {
                    if (astring[i] == alphabet[j][k]) {
                        astringnum += to_string(j + 2);
                    }
                }
            }
        }
        if (astringnum == brand) {
            fout << astring << endl;
            aresol = true;
        }
        fin >> astring;
    }

    if (!aresol)
        fout << "NONE" << endl;

    return 0;
}

/*
for each word in the dictionary
check the index of each letter in the alphabet dictionary
concat them
if it matches the id, output the name
*/