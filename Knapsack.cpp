#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
class Knapsack {


	int N, W;
	vector<int> v, w;
public:
	Knapsack() {
		scanf("%d %d",&N,&W);

		for (int i = 0; i < N; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(a);
			w.push_back(b);

		}
		vector<bool> bit(N);

		//‘S”’Tõ
		for (int i = 0; i < pow(2, N) - 1; i++) {
			int j = N - 1;

			if (!bit[j])bit[j] = true;//binary adder
			else {
				bit[j] = false;
				while (bit[j]) {
					if (bit[j]) {
						bit[j] = false;
						j--;
						continue;
					}
					else bit[j] = true;
				}
			}

		}


	}

};