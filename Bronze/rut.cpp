#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<char> dir;
	vector<int> x;
	vector<int> origx;
	vector<int> y;
	vector<int> origy;
	vector<int> rut;
	vector<int> line;
	vector<vector<int>> cc;
	vector<vector<int>> ccadd;
	int n;
	int temp;
	int done = 0;
	char tempc;
	cin >> n;

	vector<vector<int>>::iterator it;

	for (int i = 0; i < n; i++) {
		cin >> tempc;
		dir.push_back(tempc);
		cin >> temp;
		x.push_back(temp);
		origx.push_back(temp);
		cin >> temp;
		y.push_back(temp);
		origy.push_back(temp);
		rut.push_back(-1);
	}

	while (done != n) {
	    ccadd = {};
		for (int i = 0; i < n; i++) {
			if (dir[i] == 'E') {
				x[i]++;
				line = {x[i], y[i]};
				it = find(cc.begin(), cc.end(), line);
				if (it != cc.end()) {
					dir[i] = 'Q';
					rut[i] = x[i] - origx[i];
					done++;
				} else {
				  	ccadd.push_back({x[i], y[i]});
				  	if (x[i] == *max_element(x.begin(), x.end())) {
				  		dir[i] = 'Q';
				  		done++;
				  	}
				}
			} else if (dir[i] == 'N') {
				y[i]++;
				line = {x[i], y[i]};
				it = find (cc.begin(), cc.end(), line);
				if (it != cc.end()) {
					dir[i] = 'Q';
					rut[i] = y[i] - origy[i];
					done++;
				} else {
				  	ccadd.push_back({x[i], y[i]});
				  	if (y[i] == *max_element(y.begin(), y.end())) {
				  		dir[i] = 'Q';
				  		done++;
				  	}
				}
			}
		}
		for (int i = 0; i < ccadd.size(); i++) {
		    cc.push_back(ccadd[i]);
		}
	} 

	for (int i = 0; i < n; i++) {
		if (rut[i] == -1) {
			cout << "Infinity" << endl;
		} else {
			cout << rut[i] << endl;
		}
	}

	return 0;
}