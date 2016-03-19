// 12121527 이성온

#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int testCase = 0;

	cin >> testCase;
	while (testCase != 0) {
		int floor = 0;		// 층수
		int day = 0;		// 일수
		int heat = 0;		// 난방의 총합
		int zeroIndex = -1; // 맨 위층에서 아래로 내려가며 탐색할 때 가장먼저 난방이 0이 나오는 집

		cin >> floor >> day;		

		while (day != 0) {
			short apt[500][500] = { { 0, }, }; // 난방

			// 0, 1, 2 ... i-1층
			for (int i = 0; i < floor; i++) {
				cin >> apt[i][0];
				heat = heat + apt[i][0];	// 각 층의 가장 첫번째 집의 열량을 모두 더해줌
			}
			// i-1층의 1,2, ... i-1 동(0동은 이전 반복문에서 채움)
			for (int j = 1; j < floor; j++) {
				cin >> apt[floor - 1][j];
				heat = heat + apt[floor - 1][j];  // 맨 윗층의 두번째부터 끝까지의 집의 열량을 모두 더해줌
			}

			for (int k = floor - 1; k >= 0; k--) {
				if (apt[k][0] == 0) {
					zeroIndex = k;
					break;
				}
			}

			// 난방이 0인 집이 나올 경우 그 집의 오른쪽, 밑 집은 모두 0 이므로 계산에서 제외
			if (zeroIndex != -1) {
				for (int f = floor - 2; f > zeroIndex; f--) {
					for (int d = 1; d <= floor - 1; d++) {

						// 왼쪽, 왼쪽 위, 윗집의 난방 중 최소값을 구하는 과정
						if (apt[f][d - 1] < apt[f + 1][d - 1]) {
							if (apt[f][d - 1] < apt[f + 1][d]) {
								apt[f][d] = apt[f][d - 1];
								heat = heat + apt[f][d];		// 최소값을 구한 뒤 해당 집에 난방을 복사하고 전체 값에 더해주기
							}
							else {
								apt[f][d] = apt[f + 1][d];
								heat = heat + apt[f][d];
							}
						}
						else {
							if (apt[f + 1][d - 1] < apt[f + 1][d]) {
								apt[f][d] = apt[f + 1][d - 1];
								heat = heat + apt[f][d];
							}
							else {
								apt[f][d] = apt[f + 1][d];
								heat = heat + apt[f][d];
							}
						}
					}
				}
			}
			// 난방이 0인 집이 하나도 나오지 않을 경우

			else {
				for (int f = floor - 2; f >= 0; f--) {
					for (int d = 1; d <= floor - 1; d++) {
						if (apt[f][d - 1] < apt[f + 1][d - 1]) {
							if (apt[f][d - 1] < apt[f + 1][d]) {
								apt[f][d] = apt[f][d - 1];
								heat = heat + apt[f][d];
							}
							else {
								apt[f][d] = apt[f + 1][d];
								heat = heat + apt[f][d];
							}
						}
						else {
							if (apt[f + 1][d - 1] < apt[f + 1][d]) {
								apt[f][d] = apt[f + 1][d - 1];
								heat = heat + apt[f][d];
							}
							else {
								apt[f][d] = apt[f + 1][d];
								heat = heat + apt[f][d];
							}
						}
					}
				} // 한 날의 열량 계산 끝
			}
			day--;
		}

		cout << heat << endl;

		testCase--;
	}


	return 0;
}