/*
ID: swarnya1
TASK: wormhole
LANG: C++14
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int partner[MAX_N+1];
int next_on_right[MAX_N+1];

bool cycle_exists(void)
{
  for (int start=1; start<=N; start++) {
    // does there exist a cylce starting from start
    int pos = start;
    for (int count=0; count<N; count++)
      pos = next_on_right[partner[pos]];
    if (pos != 0) return true;
  }
  return false;
}

// count all solutions
int solve(void) 
{
  // find first unpaired wormhole
  int i, total=0;
  for (i=1; i<=N; i++) 
    if (partner[i] == 0) break;

  // everyone paired?
  if (i > N) {
    if (cycle_exists()) return 1;
    else return 0;
  }

  // try pairing i with all possible other wormholes j
  for (int j=i+1; j<=N; j++)
    if (partner[j] == 0) {
      // try pairing i & j, let recursion continue to 
      // generate the rest of the solution
      partner[i] = j;
      partner[j] = i;
      total += solve();
      partner[i] = partner[j] = 0;
    }
  return total;
}

int main(void)
{
  ifstream fin("wormhole.in");
  fin >> N;
  for (int i=1; i<=N; i++) fin >> X[i] >> Y[i];
  fin.close();
  
  for (int i=1; i<=N; i++) // set next_on_right[i]...
    for (int j=1; j<=N; j++)
      if (X[j] > X[i] && Y[i] == Y[j]) // j right of i...
	if (next_on_right[i] == 0 ||
	    X[j]-X[i] < X[next_on_right[i]]-X[i])
	  next_on_right[i] = j;

  ofstream fout("wormhole.out");
  fout << solve() << "\n";
  fout.close();
  return 0;
}

/*int dig(int n, int m)
{
	for (int i = 0; i < n; i++) {
	    for (int j = i + 1; j < n; j++) {
			pairs[j] = i;
			pairs[i] = j;
			total += dig();
			pairs[i] = -1;
			pairs[j] = -1;
	    }
	}
	total += 1;
}

int main() {
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");

	vector<int> x;
	vector<int> y;

	int n;
	int x_temp;
	int y_temp;
	int portals = 0;
	int combos;
	vector<int> pairs;

	for (int i = 0; i < n; i++) {
		pairs.push_back(-1);
	}

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x_temp;
		cin >> y_temp;

		x.push_back(x_temp);
		y.push_back(y_temp);
	}

	for (int i = 0; i < n; i++) {
	    for (int j = i + 1; j < n; j++) {
	        if (y[i] == y[j]) {
	            portals++;
    			pairs[j] = i;
    			pairs[i] = j;
	        }
	    }
	}
*/
	/*
	4
    21 7
    11 23
    11 7
    5 10
    		
    6
    1 15
    20 15
    17 11
    22 21
    25 11
    20 17
	if (n <= 2)
		combos = 1;
	else if (portals > 0 && n > 4)
		combos = portals * ((n - 2) * (n - 3) / 4);
	else
		combos = portals;
	cout << portals << endl;
	*/
	/*
	cout << combos << endl;
	
	return 0;
}*/