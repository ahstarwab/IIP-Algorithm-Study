#include <iostream>
#include <vector>
#include <cstdlib>

const int MAX = 12;
const int INF = 987654321;

using namespace std;
int n;
int coord[MAX][2];
int dist[MAX][MAX];
int cache[MAX][1 << MAX]; // [지금 방문한 도시][지금까지 걸어온 길] = 지금까지 걸어온 거리

int TSP(int visit_log, int cur)
{

	if (visit_log == (1 << n) - 1 - 2) //모두 방문(도착지 빼고)
	{
		return dist[cur][1]; // 집으로 가는 거리

	}

	int& total_dist = cache[cur][visit_log];
	
	if (total_dist > 0) //이미 방문
		return total_dist;

	total_dist = INF;

	for (int i = 2; i < n; i++)
	{
		//if (i == 1) //집(도착지)은 마지막에 방문할거니깐
			//continue;

		if (visit_log & (1 << i)) //이미 방문
			continue;


		if (cur == i)
			continue;
		
		total_dist = min( total_dist, TSP( (visit_log | (1 << i)), i )  + dist[cur][i]);


	}

	return total_dist;



}


void COORD_2_DIST(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = abs(coord[i][0] - coord[j][0]) + abs(coord[i][1] - coord[j][1]);

		}
	}


}

void initialize(void)
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < (1 << MAX); j++)
			cache[i][j] = -1;
}


int main(void)
{
	// Just for fast cin
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testcase;

	cin >> testcase;
	if (testcase < 2 || testcase > 10)
		return -1;

	for (int tc = 0; tc < testcase; tc++)
	{
		cin >> n; //고객의 수
		n += 2;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> coord[i][j];
			}
		}

		COORD_2_DIST(n);
		initialize();
		double ret = TSP(1, 0); // 현재까지 방문한 bit, 시작 노드

		cout << '#' << tc + 1 << " " << ret << endl; // minimum cost

	}
	return 0;
}

