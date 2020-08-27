//#include "bits/stdc++.h"
#include <iostream>
#include<string>
#include<cstring>
#include <algorithm>
#include <vector>
#define EPS 1E-13
using namespace std;
#include<math.h>

double gravity(int m1, double dist) {
	return (double)m1 / (dist*dist);
}


double bisection(vector<pair<double, int>>& ball, vector<pair<double, int>>::iterator first, vector<pair<double, int>>::iterator second) {

	vector<pair<double, int>>::iterator ckpt = first;
	

	double mid;// = (first->first + second->first) / 2;
	double left_gravity, right_gravity;
	double gizun_l= first->first, gizun_r=second->first;
	double tmp;
	
	do {
		left_gravity = 0.0, right_gravity = 0.0;
		mid = (gizun_l + gizun_r) / 2;
		
		while (first != ball.begin()) {
			left_gravity += gravity(first->second, mid - first->first);
			first--;
		}

		left_gravity += gravity(first->second, mid - first->first);


		while (second != ball.end()) {
			right_gravity += gravity(second->second, mid - second->first);
			second++;
		}

		if (abs(left_gravity - right_gravity) < EPS) {
			return mid;
		}

		else if (left_gravity > right_gravity) {
			first = ckpt;
			second = first + 1;
			gizun_l = mid;
			
			
		}

		else if (left_gravity < right_gravity) {
			first = ckpt;
			second = first + 1;
			gizun_r = mid;
			
		}


		// 무한루프 방지
		if (mid == (gizun_l + gizun_r) / 2) {
			break;
		}


	} while (abs(left_gravity - right_gravity) > EPS);


	

	return mid;
}



void func_1245(vector<pair<double, int>> &ball) {
	
	vector<pair<double, int>>::iterator it = ball.begin();
	double result;
	while ((it+1) != ball.end()) {
		
		result = bisection(ball, it, it + 1);
		//printf(" %.10f", floor(result*(10000000000))/10000000000);
		printf(" %.10f", result);
		it++;

	}

}



int main(void) {
	// Just for fast cin
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testcase, count;
	int coord[10], mass[10];
	cin >> testcase;

	for (int tc = 0; tc < testcase; tc++) {
		
		cin >> count;
		
		vector<pair<double, int>> ball;
	
		for (int c = 0; c < count; c++) {
			cin >> coord[c];
		}

		for (int c = 0; c < count; c++) {
			cin >> mass[c];
		}

		for (int c = 0; c < count; c++) {
			ball.push_back(make_pair(coord[c], mass[c]));
		}

		//1. sort balls
		sort(ball.begin(), ball.end());

		printf("#%d", tc + 1);
		

		func_1245(ball);

		printf("\n");
		 

	}

	return 0;
}
