#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> nums;
	int temp;
	int n;
	int total;
	int count = 0;
	int local_count;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		nums.push_back(temp);
	}

    //if (n > 1) {
    	for (int i = 0; i < n; i++) {
    	    //cout << "i: " << i << endl;
    		for (int j = 1; j <= n - i; j++) {
    		    //cout << "j: " << j << endl;
    			total = 0;
    			local_count = 0;
    			for (int k = i; k < i + j; k++) {
    				total += nums[k];
    			}
    			for (int k = i; k < i + j; k++) {
    			    //cout << i << " " << j << " " << k << endl;
    				if (nums[k]*j == total) {
    					local_count++;
    					//cout << total << " " << i << " " << j << " " << k << endl;
    				}
    				//cout << "REG " << total << " " << i << " " << j << " " << k << endl;
    			}
    			if (local_count > 0)
    			    count++;
    		}
    	}
    //}

	cout << count << endl;

	return 0;
}