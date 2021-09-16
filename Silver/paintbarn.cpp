#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    ifstream fin;
    ofstream fout;
    fin.open("paintbarn.in");
    fout.open("paintbarn.out");

	int n, k;
	fin >> n >> k;
    
    int x1, y1, x2, y2;
    vector<vector<int>> fence(1001, vector<int>(1001, 0));
    
    for (int i = 0; i < n; i++) {
        fin >> x1 >> y1 >> x2 >> y2;
        x2--; y2--;
        for (int j = x1; j <= x2; j++) {
            fence[j][y1]++;
            fence[j][y2 + 1]--;
        }
    }

    int squares = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            fence[i][j] += fence[i][j - 1];
            if (fence[i][j] == k)
                squares++;
        }
    }
/*
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
        	cout << fence[i][j] << " ";
        }
        cout << endl;
    }
*/
    fout << squares << endl;

    return 0;
}

/*
g++ -o output template.cpp
./output
*/