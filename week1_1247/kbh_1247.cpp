/*
 *https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD&categoryId=AV15OZ4qAPICFAYD&categoryType=CODE
 * */

//https://hsp1116.tistory.com/40

#include <stdio.h>
#include <algorithm>

#define MAX_IDX 4096 // 2^12
#define MAX_DIST 10000

int cache[12][MAX_IDX];
int dist[12][12];
int num_node;
int last;

int TSP(int cur,int visited){
  // time to visit last node
  if(visited == last){
    /*
    for(int k=0;k<num_node;k++){
        if(visited&(1<<k))
          printf("1");
        else
          printf("0");
      }
       printf(" %d\n",dist[cur][num_node-1]);
    printf("%d\n",dist[cur][num_node-1]);
    */
    return dist[cur][num_node-1];
  }
  int& ret = cache[cur][visited];

  //known path
  if(ret != 0)return ret;
  ret = MAX_DIST;
  
  for(int next =1;next<num_node-1;next++){
    // visited
    if(visited&(1<<next))continue;
    // do not visit self
    if(cur == next)continue;
    // TS
    ret = std::min(ret,TSP(next,visited|(1<<next))+dist[cur][next]);
  }
  return ret;
}

int main(){
  int num_test_case = 0;
  int i,j,k,l;

  int x[12];
  int y[12];
  int ans;

  scanf("%d",&num_test_case);

  for(i=0;i<num_test_case;i++){
    scanf("%d",&num_node);
    num_node+=2;
    scanf("%d %d",&x[0],&y[0]);
    scanf("%d %d",&x[num_node-1],&y[num_node-1]);
    for(j=1;j<num_node-1;j++){
      scanf("%d %d,",&x[j],&y[j]);
    }

    for(j=0;j<num_node;j++)
      for(k=0;k<MAX_IDX;k++)
        cache[j][k]=0;

    /* Create Distance map */
    for(j=0;j<num_node;j++){
      for(k=0;k<num_node;k++){
          dist[j][k] = abs(x[j]-x[k])+abs(y[j]-y[k]);
      }
    }

    last =0;
    for(int j=0;j<num_node-1;j++){
      last |=(1<<j);
    }
    /*
     for(int k=0;k<num_node;k++){
        if(last&(1<<k))
          printf("1");
        else
          printf("0");
      }
       printf("\n");
     */ 
     ans = TSP(0,1); 

    printf("#%d %d\n",i+1,ans);
  }
  return 0;
}
