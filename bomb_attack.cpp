
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;

class Bomb_Attack {
	vector <vector <char> >map;//�N�\�p�@
	int num_Enemy;
	int H, W;

public:
	void DataReader() {

		ifstream ifs("data.data");

		string str;

		if (ifs.fail()) {
			cerr << "File do not exist.\n";
			exit(0);
		}

		getline(ifs, str);

		sscanf(str.data(), "%d %d", &H, &W);
		map.resize(H);

		for (int i = 0; i < H; i++) map[i].resize(W);


		num_Enemy = 0;

		for (int i = 0; i < H; i++) {
			getline(ifs, str);
			const char* tmp = str.data();
			for (int j = 0; j < W; j++) {
				map[i][j] = *(tmp + j);
				if (map[i][j] == 'X')num_Enemy++;
			}
		}
		for (int i = 0; i < H; i++) {

			for (int j = 0; j < W; j++) {
				if (map[i][j] > '0' && map[i][j] <= '9')bomb_attack(i, j);

			}
		}
		IsSolve();
	}

	void bomb_attack(int i, int j) {

		int number = map[i][j] - '0';


		queue<int>qi, qj;
		//vector<vector<bool>>check(H,vector<bool>(W,0));
		for (int k = 1; k <= number; k++) {
			if (map[i + k][j] == '#')break;
			qi.push(i + k); qj.push(j + k);
		}
		for (int k = 1; k <= number; k++) {
			if (map[i][j + k] == '#')break;

			qi.push(i); qj.push(j + k);
		}
		for (int k = 1; k <= number; k++) {
			if (map[i - k][j] == '#')break;
			qi.push(i - k); qj.push(j);
		}
		for (int k = 1; k <= number; k++) {
			if (map[i][j - k] == '#')break;
			qi.push(i); qj.push(j - k);
		}

		while ((!qj.empty() && !qi.empty())) {
			i = qi.front();
			qi.pop();
			j = qj.front();
			qj.pop();


			if (map[i][j] == 'X') {
				map[i][j] = '.';
				num_Enemy--;
			}

		}
	}

	void IsSolve() {
		if (num_Enemy < 1)printf("YES\n");
		else puts("NO");
	}

};