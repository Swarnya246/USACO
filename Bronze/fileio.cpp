#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
ofstream fout("fileio.out");
ifstream fin("fileio.in");

int n;

fin >> n;
fout << n;

return 0;
}