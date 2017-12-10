
#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
class ABC081D {
	int N;
	vector<long int>A;

	int adder(vector<long int>a, int i) {
		int min = 1000000, index = min;
		for (int j = 0; j < N; j++) {
			if (a[i] + a[j]< a[i + 1] && min>a[j]) {
				min = a[j];
				index = j;
			}
		}
		a[i] += a[index];
		return index;

	}
	ABC081D() {
		cin >> N;
		int i = 0, c = 0;
		while (i < N) {
			int num;
			cin >> num;
			A.push_back(num);
			i++;
		}

		i = 0;

	L:
		bool end = true;
		for (int j = 0; j < N - 1; j++) {
			if (A[j] > A[j + 1]) {
				printf("%d %d\n ", adder(A, j), j);
				end = false;
			}
		}
		if (!end)goto L;
	}
};