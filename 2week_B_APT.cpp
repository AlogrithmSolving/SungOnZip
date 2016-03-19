// 12121527 �̼���

#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int testCase = 0;

	cin >> testCase;
	while (testCase != 0) {
		int floor = 0;		// ����
		int day = 0;		// �ϼ�
		int heat = 0;		// ������ ����
		int zeroIndex = -1; // �� �������� �Ʒ��� �������� Ž���� �� ������� ������ 0�� ������ ��

		cin >> floor >> day;		

		while (day != 0) {
			short apt[500][500] = { { 0, }, }; // ����

			// 0, 1, 2 ... i-1��
			for (int i = 0; i < floor; i++) {
				cin >> apt[i][0];
				heat = heat + apt[i][0];	// �� ���� ���� ù��° ���� ������ ��� ������
			}
			// i-1���� 1,2, ... i-1 ��(0���� ���� �ݺ������� ä��)
			for (int j = 1; j < floor; j++) {
				cin >> apt[floor - 1][j];
				heat = heat + apt[floor - 1][j];  // �� ������ �ι�°���� �������� ���� ������ ��� ������
			}

			for (int k = floor - 1; k >= 0; k--) {
				if (apt[k][0] == 0) {
					zeroIndex = k;
					break;
				}
			}

			// ������ 0�� ���� ���� ��� �� ���� ������, �� ���� ��� 0 �̹Ƿ� ��꿡�� ����
			if (zeroIndex != -1) {
				for (int f = floor - 2; f > zeroIndex; f--) {
					for (int d = 1; d <= floor - 1; d++) {

						// ����, ���� ��, ������ ���� �� �ּҰ��� ���ϴ� ����
						if (apt[f][d - 1] < apt[f + 1][d - 1]) {
							if (apt[f][d - 1] < apt[f + 1][d]) {
								apt[f][d] = apt[f][d - 1];
								heat = heat + apt[f][d];		// �ּҰ��� ���� �� �ش� ���� ������ �����ϰ� ��ü ���� �����ֱ�
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
			// ������ 0�� ���� �ϳ��� ������ ���� ���

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
				} // �� ���� ���� ��� ��
			}
			day--;
		}

		cout << heat << endl;

		testCase--;
	}


	return 0;
}