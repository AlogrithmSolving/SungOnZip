// 12121527 �̼���

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int blankNum;   // ĭ ��ȣ_���۹�ȣ �� �״��, ����ȣ �� ��ȣ��+1
	int serial;     // �ø��� ��ȣ_1�̸� ���۹�ȣ, -1�̸� ����ȣ
}colorPair;

// colorPair ����ü ���Լ�, ������������ ����
bool cmp(colorPair A, colorPair B) {
	return A.blankNum < B.blankNum;
} 

int main() {
	std::ios::sync_with_stdio(false);

	int testCase = 0;
	int colorNum = 0, overlap = 0; // ������ ��, ��ĥ�� ���� ��
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> colorNum >> overlap;
		
		colorPair a;
		colorPair blank[3050] = { a, };

		// ���� ���� �Է�
		for (int j = 0; j < colorNum*2; j++) {
			//colorPair a;
			// ���۹�ȣ �Է� ��
			if (j % 2 == 0) {
				cin >> blank[j].blankNum;
				blank[j].serial = 1;
			} 
			// ����ȣ �Է� ��
			else if(j%2 != 0) {
				cin >> blank[j].blankNum;
				blank[j].blankNum = blank[j].blankNum + 1;
				blank[j].serial = -1;
			}
		}
		// sorting
		sort(blank, blank + (colorNum*2), cmp);

		// �ߺ��� ������ ���� ���� ��
		for (int p = 0; p < colorNum * 2; p++) {
			if (blank[p].blankNum == blank[p - 1].blankNum && blank[p].serial + blank[p-1].serial == 0 ) {
				blank[p-1].blankNum = 0;	// �� ���� �ߺ��� ������ colorPair�� ���� �� ���� colorPair�� <0,0>���� �ʱ�ȭ
				blank[p-1].serial = 0;
				blank[p].serial = 0;        // ���� colorPair�� ������ blankNum�� serial�� 0���� �ʱ�ȭ �� <blankNum, 0>
			} 
		}
		// sorting
		sort(blank, blank + (colorNum * 2), cmp);

		
		int count = 0;
		int startNum = 0;
		for (int k = 0; k < colorNum * 2; k++) {
			// ���� --> colorPair�� ���� <blankNum, serial>
			// <0,0> �� colorPair�� ����
			if (blank[k].blankNum == 0) {
				continue;
			}
			// <blankNum, 1> �� colorPair�� ī����
			if (blank[k].serial == 1) {
				count++;
				startNum = blank[k].blankNum;
			}
			// <blankNum, -1>�� colorPair�� ��ī����
			else if (blank[k].serial == -1) {
				count--;
				startNum = blank[k].blankNum;
			}
			// ī���� Ƚ���� overlap(=�������� K��)�� ���� ���� colorPair�� serial�� 0�� �ƴϸ�, ���������� blankNum�� ����������
			// ���
			// k=1 1~3 4~5 6~9 �Է� �� 1~9 ���
			// k=3 5~5 5~7 5~5 �Է� �� 5~5 ���
			// k=2 5~5 5~7 5~5 �Է� �� ��¾���
			if (count == overlap && blank[k + 1].serial != 0 && blank[k].blankNum != blank[k+1].blankNum) {
				cout << startNum << " " << blank[k + 1].blankNum - 1 << endl;
			}
		}
	}

	return 0;
}
