//#include "bits/stdc++.h"
#include <iostream>
#include<string>
#include<cstring>
#include <algorithm>
#include <vector>
using namespace std;

string swap(string number, int idx1, int idx2) {
	char tmp = number[idx1];
	number[idx1] = number[idx2];
	number[idx2] = tmp;
	return number;
}


int func_1244(string number, int cnt, int idx) {
	if (cnt == 0)
		return stoi(number);

	int length = number.length();

	if (idx == length - 1 && cnt == 0) {
		return stoi(number);
	}

	else if (idx == length - 1 && cnt != 0) {

		if(number[length-2] == number[length-3])
			return func_1244(number, cnt-1, idx);
		
		string tmp = swap(number, idx, idx - 1);
		return func_1244(tmp, cnt-1, idx);
	}

	else {
		char max = number[idx];
		//int max_idx = idx;

		//For Brute-Force
		vector<int> idx_vector;

		for (int i = idx + 1; i < length; i++) {
			//for (int i = length-1; i >= idx + cnt; i--) {
			if (number[i] >= max) {
				//max_idx = i;
				//idx_vector.push_back(i);
				max = number[i];
			}
		}
		for (int i = idx + 1; i < length; i++) {
			//for (int i = length-1; i >= idx + cnt; i--) {
			if (number[i] == max) {
				//max_idx = i;
				idx_vector.push_back(i);
			}
		}

		int ret = -1;
		int rec;

		if (idx_vector.size() == 0) {
			return func_1244(number, cnt, idx + 1);
		}


		for (vector<int>::iterator it = idx_vector.begin(); it != idx_vector.end(); ++it) {
			// it might be slow
			string tmp = swap(number, idx, *it);

			rec = func_1244(tmp, cnt - 1, idx + 1);
			if (rec >= ret) {
				ret = rec;
			}
		}

		return ret;
	}
	//SWAP
	/*char tmp = number[max_idx];
	number[max_idx] = number[idx];
	number[idx] = tmp;

	swap(number, --cnt, ++idx);*/

}



int main(void) {
	// Just for fast cin
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testcase;
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++) {

		string number;
		int cnt; // 사전 포함 단어수 , 입력 단어수
		int result;
		cin >> number >> cnt;

		//sort(number.begin(), number.begin() + cnt, greater<int>());

		result = func_1244(number, cnt, 0);

		cout << '#' << tc+1 << ' ' << result << '\n';

	}

	return 0;
}
