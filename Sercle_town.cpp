#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
class Sercle_town {

	//���S�~��Ə\���ɓ��̂���X�ŁC�o���_�ƖړI�n�̍ŒZ�o�H���Z�o����
	int start, distination,N; 
	char start_direction,distination_direction;
public:
	Sercle_town() {
		scanf("%d", &N);
		scanf("%d %c", &start, &start_direction);
		scanf("%d %c", &distination, &distination_direction);

		start *= 100;
		distination *= 100;
		if (start_direction == 'W') {
			start_direction = 'E';
			start *= -1;

		}
		if (distination_direction == 'W') {
			distination_direction = 'E';
			distination *= -1;


		}
		if (start_direction == 'S') {
			start_direction = 'N';
			start *= -1;

		}
		if (distination_direction == 'S') {
			distination_direction = 'N';
			distination *= -1;
		}

		//���꒼����
		if (distination_direction == start_direction) {
			printf("%lf\n", (double)(abs(distination - start)));

		}

		//�Ȃ��蓹���܂߂鎞
		else {
			vector<double> distance(N+1);
			double min_distance=100*100;
			distination = abs(distination);
			start = abs(start);
			for (int i = 0; i <= N; i++) {
				
				distance[i] = abs(-100 * i + start) + abs(100 * i - distination) + 50 * i*3.1415926535897932384626433832795;
				if (distance[i] < min_distance)min_distance = distance[i];
			}
			printf("%lf\n",min_distance);
		}
	}

};