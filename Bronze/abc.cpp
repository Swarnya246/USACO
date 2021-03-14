#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	vector<int> nums;
	int temp;

	for (int i = 0; i < 7; i++) {
		cin >> temp;
		nums.push_back(temp);
	}
	
	sort(nums.begin(), nums.end());

	a = nums[0];
	b = nums[1];
	c = nums[6] - a - b;

	cout << a << " " << b << " " << c << endl;

	return 0;
}