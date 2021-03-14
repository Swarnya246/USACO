/*
ID: swarnya1
TASK: tttt
LANG: C++14
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	vector<string> board;
	char temp[3];
	string temp1;
	int breaks;
	int iv = 0;
	int tv = 0;

	ifstream fin("tttt.in");
	ofstream fout("tttt.out");

	for (int i = 0; i < 3; i++) {
		fin >> temp1;
		board.push_back(temp1);
	}

	temp[0] = board[0][0];
	temp[1] = board[0][1];
	temp[2] = board[0][2];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[1][0];
	temp[1] = board[1][1];
	temp[2] = board[1][2];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[2][0];
	temp[1] = board[2][1];
	temp[2] = board[2][2];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[0][0];
	temp[1] = board[1][0];
	temp[2] = board[2][0];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[0][1];
	temp[1] = board[1][1];
	temp[2] = board[2][1];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[0][2];
	temp[1] = board[1][2];
	temp[2] = board[2][2];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[0][0];
	temp[1] = board[1][1];
	temp[2] = board[2][2];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
	temp[0] = board[0][2];
	temp[1] = board[1][1];
	temp[2] = board[2][0];
	breaks = 0;
	for (int i = 0; i < 2; i++) {
		if (temp[i] != temp[i + 1]) {
			breaks++;
		}
	}
	if (temp[0] != temp[2])
	    breaks++;
	if (breaks == 0) 
		iv++;
	if (breaks == 2)
		tv++;
    
    fout << iv << endl << tv + iv << endl;
	fout.close();
	return 0;
}