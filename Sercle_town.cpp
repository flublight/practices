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

	//同心円状と十字に道のある街で，出発点と目的地の最短経路を算出する
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

		//同一直線時
		if (distination_direction == start_direction) {
			printf("%lf\n", (double)(abs(distination - start)));

		}

		//曲がり道を含める時
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