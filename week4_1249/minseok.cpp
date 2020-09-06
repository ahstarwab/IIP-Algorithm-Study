//#include <iostream>
//#include <queue>
//

//using namespace std;
//
//int Dijkstra()

#include<stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define VERTEX 100 // vertex �ִ� ��
#define MYINF 9999
using namespace std;
int board[VERTEX][VERTEX];
int cost[VERTEX][VERTEX]; 

//vector< pair<int, int> > adj[MAX_V]; 

void dijkstra(int size)
{

    priority_queue<pair<int, pair<int, int> > > pq; // (cost, ��ǥ)

    pq.push(make_pair(0, make_pair(0, 0))); // �������� cost=0
    cost[0][0] = 0; // cost : ������� �ּҰŸ�

    while (!pq.empty())
    {
        
        pair<int, int> cur_vertex = pq.top().second;
        int cur_cost = -pq.top().first; ////cost[cur_vertex.first][cur_vertex.second]; //
        pq.pop();

        // �� ª�� ��ΰ� �ִٸ� ����
        if (cost[cur_vertex.first][cur_vertex.second] < cur_cost)
            continue;

        // 4���� �˻�
        // 1.
        int x, y, next_cost;

        x = cur_vertex.first+1; y = cur_vertex.second;
        if (x < size && y < size && x >= 0 && y >= 0) {
            next_cost = cur_cost + board[x][y];//���ݱ��� cost + ���� cost
            if (cost[x][y] > next_cost) {
                cost[x][y] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(x, y)));
            }
        }

        x = cur_vertex.first; y = cur_vertex.second + 1;
        if (x < size && y < size && x >= 0 && y >= 0) {
            next_cost = cur_cost + board[x][y];//���ݱ��� cost + ���� cost
            if (cost[x][y] > next_cost) {
                cost[x][y] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(x, y)));
            }
        }

        x = cur_vertex.first-1; y = cur_vertex.second;
        if (x < size && y < size && x >= 0 && y >= 0) {
            next_cost = cur_cost + board[x][y];//���ݱ��� cost + ���� cost
            if (cost[x][y] > next_cost) {
                cost[x][y] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(x, y)));
            }
        }
        x = cur_vertex.first; y = cur_vertex.second-1;
        if (x < size && y < size && x >= 0 && y >= 0) {
            next_cost = cur_cost + board[x][y];//���ݱ��� cost + ���� cost
            if (cost[x][y] > next_cost) {
                cost[x][y] = next_cost;
                pq.push(make_pair(-next_cost, make_pair(x, y)));
            }
        }
    }
}

int main() {
	
	int tc, size;
    char a;
	scanf("%d", &tc);
	for(int i = 0; i<tc; i++) {
		scanf("%d", &size);
		getchar();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				scanf("%c", &a);
                board[i][j] = a - '0';
;			}
            
			getchar();
		}


        //memset(cost, 9999, sizeof(cost));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cost[i][j] = 9999;
            }
        }

        dijkstra(size);
        printf("#%d %d\n", i+1, cost[size-1][size-1]);
	}
	return 0;
}