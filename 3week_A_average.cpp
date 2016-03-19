// 12121527 �̼���

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int testCase = 0;

	cin >> testCase;
	while (testCase != 0) {
		double min_most = 10; // ���� ���� ��
		double max_most = 0;  // ���� ū ��
		double min_next = 10; // �ι�°�� ���� ��
		double max_next = 0;  // �ι�°�� ū ��
		double adjust_average = 0; // �������
		double cut_average = 0;    // �������
		double sum = 0;		  // ����
		double temp = 0;      // �Է��ϴ� ��
		int inputNum = 0;     // �Է��ϴ� ������ ����
		int tempInputNum = 0; // �ӽ� �Է��ϴ� ������ ����

		cin >> inputNum;
		tempInputNum = inputNum;
		while (inputNum != 0) {
			cin >> temp;

			sum = sum + temp;

			// ���� ū ��
			if (max_most < temp) {
				max_most = temp;
			}
			// ���� ���� ��
			if (min_most > temp) {
				min_most = temp;
			}

			// �ι�°�� ū ��
			if (max_next < temp && max_most > temp) {
				max_next = temp;
			}
			// �ι�°�� ���� ��
			if (min_next > temp && min_most < temp) {
				min_next = temp;
			}
			
			inputNum--;
		}
		
		inputNum = tempInputNum;
		// �������
		sum = sum - (max_most + min_most); // ���� ū ��, ���� ���� ���� �� ���� ���ϱ�
		cut_average = sum / (inputNum - 2);
		cout.setf(ios::showpoint);	// �Ҽ����ڸ��� 0�� ���͵� ǥ��
		cout.precision(4);			// ���� ū �ڸ� ������ 4° �ڸ����� �Ҽ��� ǥ��
		cout << cut_average << " ";

		// �������, �������
		sum = sum - (max_next + min_next) + (max_most + min_most); // �ι�°�� ū ��, �ι�°�� ���� ���� �� ���� ���ϱ� 
		adjust_average = sum / (inputNum - 2);
		cout.setf(ios::showpoint);
		cout.precision(4);
		cout << adjust_average << endl;

		testCase--;
	}

	return 0;
}