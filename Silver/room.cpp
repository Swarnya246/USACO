#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return (a.first.first < b.first.first);
}

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/
    
    int n;
    cin >> n;
    int x, y;
    vector<pair<pair<int, int>, int>> v(n);

    /*
    sort by arrival time
    queue for departure time
    */

    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), compare);

    vector<int> ans(n);
    int rooms = 0;
    int room = 0;
    priority_queue<pair<int, int>> pq; // min pq, smallest departure time at top, -departure time and room
    /*
    case 1: nothing in priority queue
        ans = last
    case 2: arrival time > last element in priority queue (need a while loop)
        pop last element
        ans = last
    case 3: arrival time <= last element in priority queue (need a while loop)
        ans = last++

    put things in priority queue always
    */
    for(int i = 0; i < n; i++) {
        if (pq.empty()) {
            room++;
            pq.push(make_pair(-v[i].first.second, room));
            ans[v[i].second] = room;
        }
        else {
            pair<int, int> min = pq.top();
            if (v[i].first.first > -min.first) {
                pq.pop();
                pq.push(make_pair(-v[i].first.second, min.second));
                ans[v[i].second] = min.second;
            }
            else {
                room++;
                pq.push(make_pair(-v[i].first.second, room));
                ans[v[i].second] = room;
            }
        }
        rooms = max(rooms, ans[v[i].second]);
    }

    cout << rooms << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }    

	return 0;
}

/*
g++ -o output template.cpp
./output

1 2
2 4
4 4

1 2 4
2 4 4
 if (v[i].first.first <= v[i - 1].first.second) {
    
 }
*/