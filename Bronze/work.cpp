#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("work.out");
    ifstream fin("work.in");
    
    int n;
    int start;
    int end;
    int pen;
    int max_end = 1;
    int need = 0;
    vector<vector<int>> sched;
    vector<int> pencil;
    fin >> n;
    
    for (int i = 0; i < n; i++) {
        fin >> start >> end >> pen;
        sched.push_back({start - 1, end - 1, pen});
        if (end > max_end)
            max_end = end;
    }
    
    for (int i = 0; i < max_end; i++)
        pencil.push_back(0);
        
    for (int i = 0; i < n; i++) {
        for (int j = sched[i][0]+1; j < sched[i][1]; j++) {
            pencil[j] += sched[i][2];
        }
    }
        
    for (int i = 0; i < max_end; i++) {
        if (pencil[i] > need)
            need = pencil[i];
    }
    
    fout << need << endl;
    
    return 0;
}