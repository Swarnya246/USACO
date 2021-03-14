/*
ID: swarnya1
TASK: palsquare
LANG: C++14
*/

//#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <math.h>
#include <fstream>
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string basify(vector<int>& based, int base) {
    int last_digit = based[based.size() - 1];

    if (last_digit < base) {
        string final_based = "";
        for (int i = based.size() - 1; i >= 0; i--) {
            if (based[i] > 9) {
                final_based += alphabet[based[i] - 10];
            }
            else {
                final_based += to_string(based[i]);
            }
        }
        return final_based;
    }

    based[based.size() - 1] = last_digit % base;
    based.push_back((last_digit - (last_digit % base)) / base);
    return basify(based, base);
}

bool ispal(string palindrome) {
    int size = palindrome.size();
    for (int i = 0; i <= size / 2; i++) {
        if (palindrome[i] != palindrome[size - 1 - i])
            return false;
    }
    return true;
}

int main() {
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");

    int base;
    fin >> base;

    vector<int> initial;

    for (int i = 1; i <= 300; i++) {
        initial = { i * i };
        string squarebase = basify(initial, base);
        initial = { i };
        if (ispal(squarebase))
            fout << basify(initial, base) << " " << squarebase << endl;
    }

    return 0;
}
