#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Amida {

	int L, n, m;

public:

	void Set3numberofInt(int num[3]) {
		scanf("%d %d %d", &num[0], &num[1], &num[2]);
	}

	void printarray(vector <vector <int> >map) {

		for (int i = 0; i < L; i++) {//�\��
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			}
			puts("");
		}


	}

	void SeachandGoto_edge(int now[4], vector <vector <int> >map) {

		int x = now[1], y = now[0];
		//	map[y][x][0] = -1;

		if (y == -1) {//�ŏ�ʂ܂ŗ�����I���
			return;
		}

		if (map[y][x] == 0 || (now[0] == now[2] && now[1] == now[3]))now[0]--;//�ӂ��Ȃ���Ώ�ֈړ�

		else {
			for (int i = L - 1; i > -1; i--) {//�T��
				for (int j = n - 1; j > -1; j--) {
					if (map[i][j] == map[y][x] && (i != y || j != x)) {
						now[0] = i;
						now[1] = j;
						now[2] = now[0];
						now[3] = now[1];
						goto LL;//���[�v�E�o�̂�
					}
				}
			}
		}
	LL:
		SeachandGoto_edge(now, map);//�����ċA
	}

	void amida_solver(void) {

		vector <vector <int> >map;
		scanf("%d %d %d", &L, &n, &m);


		//map = vector <vector <vector <int>>>(L, vector<vector<int>>(n, vector<int>(m,0)));//�O����Vector�̃R���X�g���N�^ map_Lnm
		map = vector <vector <int> >(L, vector<int>(n, 0));
		int t;

		for (int i = 0; i < m; i++) {

			//input data
			int input[3];
			Set3numberofInt(input);


			//i+1�͖_�����Ԓ��_�ԍ�������
			map[input[1] - 1][input[0] - 1] = i + 1;
			map[input[2] - 1][input[0]] = i + 1;//1-m�܂Œ��_�ԍ��͓o�^�����
												//(i,j)
		}


		//�S�[���n�_����X�^�[�g�n�_�ւƑk���ĒT��
		int now[4] = { L - 1,0,L - 1,0 };
		SeachandGoto_edge(now, map);

		printf("%d\n", now[1] + 1);


	}
};