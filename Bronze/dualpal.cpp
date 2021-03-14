/*
ID: swarnya1
TASK: dualpal
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
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
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");

    int n;
    fin >> n;
    int s;
    fin >> s;

    vector<int> initial;

    int test_this_num = s + 1;
    int num_sol = 0;
    int num_pals;
    int i;

    while (num_sol < n) {
        i = 2;
        num_pals = 0;
        while (num_pals < 2 && i <= 10) {
            initial = { test_this_num };
            string squarebase = basify(initial, i);
            if (ispal(squarebase)) {
                num_pals++;
            }
            i++;
        }
        if (num_pals == 2) {
            num_sol++;
            fout << test_this_num << endl;
        }
        test_this_num++;
    }

    return 0;
}
