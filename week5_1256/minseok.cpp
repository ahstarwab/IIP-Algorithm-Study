//#include "bits/stdc++.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int main(void) {
	// Just for fast cin
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testcase, count, word_len;
	cin >> testcase;
	//scanf("%d", &testcase);

	for (int tc = 0; tc < testcase; tc++) {
		cin >> count;
		//scanf("%d", &count);
		
		string word;
		vector<string> words;

		cin >> word;
		
		word_len = word.length();

		if (word_len < count) {
			printf("#%d None\n", tc + 1);
			continue;
		}



		for (int c = 0; c < word_len; c++) {
			words.push_back(word.substr(c, word_len));
		}

		//1. sort balls
		sort(words.begin(), words.end());
		printf("#%d %s\n", tc+1, words[count-1].c_str());

	}

	return 0;
}
