
#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
class ABC081C {

	int N, K;
public:

	ABC081C() {
		cin >> N;
		cin >> K;
		vector<long int>A(N);
		vector<int>num_count(N, 0);
		int i = 0, c = 0;
		while (i<N) {
			cin >> A[i];
			i++;
		}
		i = 0;

		while (i<N) {
			num_count[A[i] - 1]++;
			i++;
		}

		sort(num_count.begin(),num_count.end());
		for (i = 0; i < N-K-1; i++) {
			c++;
		}

/*
		int j = 0;
		while (j < K) {
			int max = 0;
			int index = 0;
			i = 0;
			while (i < N) {
				if (max < num_count[i]) {
					max = num_count[i];
					index = i;
				}
				i++;
			}
			num_count[index] = 0;
			j++;
		}
		
		i = 0;
		
		while (i<N) {
			c += num_count[i];
			i++;
		}
		*/
		printf("%d\n", c);

	}

};