/*
ID: swarnya1
TASK: milk
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool isCheaper(vector<int> a, vector<int> b) {
    if (a[0] < b[0])
        return true;
    return false;
}

int main() {
    ofstream fout("milk.out");
    ifstream fin("milk.in");

    int n;
    fin >> n;
    int m;
    fin >> m;
    vector<vector<int>> farmers;
    int price;
    int stock;
    int cost = 0;
    int bought = 0;

    for (int i = 0; i < m; i++) {
        fin >> price;
        fin >> stock;
        farmers.push_back({ price, stock });
    }

    sort(farmers.begin(), farmers.end(), isCheaper);

    int i = 0;
    while (i < m && bought < n) {
        price = farmers[i][0];
        stock = farmers[i][1];
        if ((n - bought) >= stock) {
            cost += stock * price;
            bought += stock;
        }
        else {
            cost += ((n - bought) * price);
            bought += (n - bought);
        }
        i++;
    }

    fout << cost << endl;

    return 0;
}