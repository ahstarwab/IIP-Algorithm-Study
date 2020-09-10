#include <iostream>
#include <vector>
#include <string>

//#include <cstring>

using namespace std;
int cache[501][501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testcase, word_len;
	cin >> testcase;


	for (int tc = 0; tc < testcase; tc++) {
		cin >> word_len;
		string word1, word2;
		cin >> word1;
		cin >> word2;
		word1 = '0' + word1;
		word2 = '0' + word2;

		for (int i = 0; i <= word_len; i++) {
			for (int j = 0; j <= word_len; j++) {

				if (i == 0 || j == 0) {
					cache[i][j] = 0;
					continue;
				}

				if (word1[i] == word2[j])
					cache[i][j] = cache[i - 1][j-1] + 1; //¿ÞÀ§ + 1
				else {
					if(cache[i][j-1] > cache[i-1][j])
						cache[i][j] = cache[i][j - 1]; //¿ÞÂÊ¿¡¼­ °¡Á®¿È 
					else
						cache[i][j] = cache[i-1][j]; //À§¿¡¼­ °¡Á®¿È 

				}


			}
		}

		// For Test
		//printf("  ");
		//for (int i = 0; i <= word_len; i++)
		//	printf("%c ", word2[i]);
		//printf("\n");

		//for (int i = 0; i <= word_len; i++) {
		//	printf("%c ", word1[i]);
		//	for (int j = 0; j <= word_len; j++) {
		//		printf("%d ", cache[i][j]);

		//	}
		//	printf("\n");
		//}

		printf("#%d %.2f\n",tc+1, (float)cache[word_len][word_len]/word_len*100);
	}
	return 0;
}