#include <bits/stdc++.h>
using namespace std;

int main() {
/*
	ifstream fin;
    ofstream fout;
    fin.open("template.in");
    fout.open("template.out");
*/
    
	int n;
	cin >> n;
	string s;
	cin >> s;

	unordered_set<char> types;

	for (int i = 0; i < n; i++) {
		types.insert(s[i]);
	};

	int left = 0;
	int right = 0;
	vector<char> v;
	unordered_map<char, int> count;
	int m = n;
	for (int i = 0; i < n; i++) {
		count[s[i]]++;
		//cout << count[s[left]] << " " << left << endl;
		while (count[s[left]] > 1) {
			// cout << left << endl;
			count[s[left]]--;
			left++;
		}
		if (count[s[i]] == 1) {
			right = i;
		}
		if (count.size() == types.size()) {
			m = min(m, right - left + 1);
		}
	}

	cout << m << endl;

	return 0;
}

/*
g++ -o output template.cpp
./output
*/