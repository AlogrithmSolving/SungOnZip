// 12121527 �̼���

#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int numA = 0, numB = 0, numC = 0; // ���� A,B,C
	int sNum = 0, dNum = 0;			  // ���ۼ���, ������
	int testCase = 0;				  // test�ϴ� ��
	int clap = 0;					  // �ڼ�

	cin >> testCase; 

	for (int i = 0; i < testCase; i++) {
		clap = 0;
		cin >> numA >> numB >> numC >> sNum >> dNum;

		// ���� ���� ���� �� ���� ���� Ž��
		for (int k = sNum; k <= dNum; k++) {
			int tempK = k;

			// ��� ���� ����, ����ΰ� �Ǹ��� �ݺ����� ó������ �̵�
			if (k%numA == 0 || k%numB == 0 || k%numC == 0) {
				clap++;
				continue;
			}
			
			// �־��� ���� �Է¹��� �� A,B,C�� �ϳ��� �����ϴ��� ���� �˻�
			while (1) {
				// 1�� �ڸ����� A,B,C�� �ִ��� �˻�
				if (k % 10 == numA || k % 10 == numB || k % 10 == numC) {
					clap++;
					break;
				}
				// ���ٸ� ���� �ڸ����� ������ 10���� ���� ������ �ٽ� �˻� ����
				k = k / 10;

				// �־��� ���� 0�� �ɶ����� �ݺ�
				if (k == 0) {
					break;
				}
			} // ���� numA,numB,numC�� �־��� ���� ����ִ��� ���� üũ ��

			k = tempK;
		}

		cout << clap << endl;
	}
	return 0;
}