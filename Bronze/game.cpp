#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("game.out");
    ifstream fin("game.in");
    
    int n;
    int step;
    
    fin >> n;
    vector<int> steps;
    vector<int> chairs;
    vector<int> moved;
    moved.push_back(1);
    
    for (int i = 0; i < n; i++) {
       fin >> step;
       steps.push_back(step);
       chairs.push_back(i + 1);
    }
    
    int player_id = 1;
    int player_index = 0;
    chairs[player_index] = 0;
    
    int step_index = 0;
    while (step_index < n) {
        player_index = player_index + steps[step_index];
        
        if (player_index >= n) {
            player_index %= n; 
        }
        
        swap(player_id, chairs[player_index]);
        
        /*
        for (int j = 0; j < n; j++)  {
            cout << chairs[j] << " ";
        }
        cout << endl << player_id << " " << player_index << " " << chairs[player_index] << endl;
        */
        
        if (find(moved.begin(), moved.end(), player_id) != moved.end()) {
            fout << chairs[player_index] << endl;
            return 0;
        } else {
            moved.push_back(player_id);
        }
        
        if (player_id == 0) {
            fout << chairs[player_index] << endl;
            return 0;
        }
        
        step_index++;
    }
    
    return 0;
}