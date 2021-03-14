/*
ID: swarnya1
TASK: transform
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool matches(vector<vector<char>> first, vector<vector<char>> second, int n) {
    bool matching = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((first[i][j] != second[i][j]) && matching) {
                matching = false;
            }
        }
    }

    return matching;
}

vector<vector<char>> ninetyClockwise(vector<vector<char>> original, int n) {
    vector<vector<char>> temp(n);

    for (int i = 0; i < n; i++) {
        temp[i] = vector<char>(n);
        for (int j = 0; j < n; j++) {
            temp[i][j] = original[n - j - 1][i];
        }
    }

    return temp;
}

vector<vector<char>> reflectLeft(vector<vector<char>> original, int n) {
    vector<vector<char>> temp(n);

    for (int i = 0; i < n; i++) {
        temp[i] = vector<char>(n);
        for (int j = 0; j < n; j++) {
            temp[i][j] = original[i][n - j - 1];
        }
    }

    return temp;
}

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");

    // initialize squares

    int n;
    fin >> n;

    char character;

    vector<vector<char>> original(n);

    for (int i = 0; i < n; i++) {
        original[i] = vector<char>(n);
        for (int j = 0; j < n; j++) {
            fin >> character;
            original[i][j] = character;
        }
    }

    vector<vector<char>> transformed(n);

    for (int i = 0; i < n; i++) {
        transformed[i] = vector<char>(n);
        for (int j = 0; j < n; j++) {
            fin >> character;
            transformed[i][j] = character;
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << temp[i][j] << " ";
        }
        fout << endl;
    }
    */

    // 1

    if (matches(ninetyClockwise(original, n), transformed, n)) {
        fout << 1 << endl;
        return 0;
    }

    // 2

    if (matches(ninetyClockwise(ninetyClockwise(original, n), n), transformed, n)) {
        fout << 2 << endl;
        return 0;
    }

    // 3

    if (matches(ninetyClockwise(ninetyClockwise(ninetyClockwise(original, n), n), n), transformed, n)) {
        fout << 3 << endl;
        return 0;
    }

    // 4

    if (matches(reflectLeft(original, n), transformed, n)) {
        fout << 4 << endl;
        return 0;
    }

    // 5

    if (matches(ninetyClockwise(reflectLeft(original, n), n), transformed, n)) {
        fout << 5 << endl;
        return 0;
    }

    if (matches(ninetyClockwise(ninetyClockwise(reflectLeft(original, n), n), n), transformed, n)) {
        fout << 5 << endl;
        return 0;
    }

    if (matches(ninetyClockwise(ninetyClockwise(ninetyClockwise(reflectLeft(original, n), n), n), n), transformed, n)) {
        fout << 5 << endl;
        return 0;
    }

    // 6

    if (matches(original, transformed, n)) {
        fout << 6 << endl;
        return 0;
    }

    // 7
    fout << 7 << endl;
}