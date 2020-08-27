//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <array>
#include <algorithm>
#include <deque>
#include <iostream>

int deci[6] ={1,10,100,1000,10000,100000};
//#define DEBUG

void num2deci(int n,std::array<int,6> d){
    int t=n;
    int length=0;
    while(t){
            d[5-length]=t%10;
            t/=10;
            length++;
        }
}
void deci2num(std::array<int,6> d,int& n){
    n=0;
    for(int i=0;i<6;i++){
            n+=d[i]*deci[5-i];
    }
}

void print(std::array<int,6> d){
    for(auto i : d){
        printf("%d",i);
    }
    printf("\n");
}

int main(){
    int nTest = 0;
    int board = 0;
    int nChange = 0;
    int length = 0;
    std::array<int,6> numbers;
    int biggest;
    int fakeChange;

    std::deque<std::array<int,6>> cases;

    scanf("%d", &nTest);
    for(int i=0;i<nTest;i++){
        // input
        scanf("%d %d",&board,&nChange);
        
        // init
        for(int j=0;j<6;j++)
            numbers[j]=0;
        int t=board;
        length = 0;
        biggest = 0;
        fakeChange=0;
        while(t){
            numbers[5-length]=t%10;
            t/=10;
            length++;
        }
#ifdef DEBUG
        printf("# Do : ");print(numbers);
#endif
       cases.push_back(numbers);

        for(int j=0;j<nChange;j++){
            int target_idx = 6-length+j;
            int big_v = numbers[target_idx];
            int big_idx = target_idx;
            bool swaped  =false;

#ifdef DEBUG
            printf("---change : %d of %d at %d with %d---\n",j,nChange,target_idx,fakeChange);
#endif

            // Chance to change is larger than length
            if(j > length ){
                if((nChange-j)%2==0){
#ifdef DEBUG
                    printf("pass\n");
#endif
                    break;
                    }
                else{
                    int nCase = cases.size(); 
                    for(int k=0;k<nCase;k++){
                        for(int l=6-length;l<5;l++){
                            std::array<int,6> t_a;
                            t_a = cases.front();
                            int t_v = t_a[l+1];
                            t_a[l+1] = t_a[l];
                            t_a[l] = t_v;
                            cases.push_back(t_a);
#ifdef DEBUG
                            printf("push 1 : ");print(t_a);
#endif
                        }
                        cases.pop_front();
                    }
                    continue;
                }
            }

            int nCase = cases.size(); 
            for(int k=0;k<nCase;k++){
                int t_n;
                std::array<int,6> t_a;
                t_a = cases.front();
                big_v = t_a[target_idx];
#ifdef DEBUG
                printf("Search for : ");print(t_a);
#endif
                // find biggest number
                for(int l=target_idx+1;l<6;l++){
                    if(t_a[l] > big_v){
                        big_v = t_a[l];
                        big_idx=l;
                        swaped=true;
                    }
                }
                //need to swap
                if(swaped){
                    //swap
#ifdef DEBUG
                    printf("swap : %d\n",big_v);
#endif
                    for(int l = target_idx;l<6;l++){
                        if(t_a[l]==big_v){
                            t_a = cases.front();
                            int t_v = t_a[target_idx];
                            t_a[target_idx] = t_a[l];
                            t_a[l]  = t_v;
                            deci2num(t_a,t_v);
                            cases.push_back(t_a);
#ifdef DEBUG
                            printf("push 2 : ");print(t_a);
#endif
                        }
                    }
                    cases.pop_front();
                }
                else{
                    nChange++;
                    fakeChange++;
                }
            }
        }

        int nCase = cases.size(); 
        for(int k=0;k<nCase;k++){
            int t_v;
            std::array<int,6> t_a;
            t_a = cases.front();
            deci2num(t_a,t_v);
            if(t_v > biggest)
                biggest = t_v;
            cases.pop_front();
        }
        printf("#%d %d\n",i+1,biggest);
        cases.clear();
    }   
    return 0;
}