// 12121527 �̼���

#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int testCase = 0;

	cin >> testCase;
	while (testCase != 0) {
		int cheeseBlock[1000] = { 0, }; // ġ����� ����� �迭
		int width = 0, height = 0;		// �־��� ġ�� ����� �ʺ�, ����
		int left_Cheese = 0, right_Cheese = 0; // �ش� �ε����� ��, �� ġ��
		int min_Cheese = 0;		    // �� �� ġ���� ���� ���� ġ��
		int temp_Cheese = 0;		// �ش� �ε����� ġ� �����۾��� �� ��, ���� �ε����� ġ��� ���� �ε����� �۾� ������ ġ�� ���� ����
		int time = 0;				// ����� ��� ġ� �Դµ� �ɸ��� �ð�
		int sum = 0;				// ���� ġ���� �ѷ�
		int front_Index = 0, back_Index = 0; // ���� ġ�� �� ù��°, ������ ��ġ

		cin >> width >> height;

		// ġ�� ���� �Է�, �� ġ���� ���� ���ϱ�
		for (int i = 0; i < width; i++) {
			cin >> cheeseBlock[i];
			sum = sum + cheeseBlock[i];
		}

		// �ε����̹Ƿ� �ʺ� -1
		back_Index = width - 1;
		
		// ġ���� ������ 0�� �ɶ� ���� �ݺ��� ���
		while (sum != 0) {
			if (sum == 0) { break; }

			left_Cheese = cheeseBlock[front_Index];

			// ù��°�� ������ �ε����� ġ��� �Ѽ����� ������Ƿ� �ݺ��� ���Ŀ� �۾�
			for (int k = front_Index + 1; k < back_Index; k++) {
				if (cheeseBlock[k] == 0) {
					continue;
				}
				right_Cheese = cheeseBlock[k + 1]; 

				// ������ ġ�� �� �ּҰ��� ���ϱ�
				if (left_Cheese >= right_Cheese) {
					min_Cheese = right_Cheese;
				}
				else if (left_Cheese < right_Cheese) {
					min_Cheese = left_Cheese;
				}
				
				temp_Cheese = cheeseBlock[k]; // �ش� ����� ġ� ���� ��� �� ���� �ε����� ġ�� ��꿡 �ʿ��ϹǷ� ��������

				// ġ�� ����
				// �� �� ġ�� �� �ּ� ������ ġ�ŭ ���ų�
				if (cheeseBlock[k] > min_Cheese) {
					sum = sum - (cheeseBlock[k] - min_Cheese);
					cheeseBlock[k] = min_Cheese;
				}
				// �ּ� ������ ġ� �ش� �ε����� ġ��� ���� ��� �ϳ��� ġ� ����
				else {
					sum = sum - 1;
					cheeseBlock[k] = cheeseBlock[k] - 1;
				}

				left_Cheese = temp_Cheese;
			}
			// �迭 �ѹ��� �� �� ó���� �� �ε����� ġ�� ����
			if (front_Index != back_Index) {
				sum = sum - (cheeseBlock[front_Index] + cheeseBlock[back_Index]);
			}
			// ���� �ε���, �� �ε����� ���� ��� �ߺ��Ǿ� ���ǹǷ� �ϳ��� ����
			else {
				sum = sum - cheeseBlock[front_Index];
			}
			// ù��°, ������ �ε��� ġ��� �׻� �ٷ� 0�� ��
			cheeseBlock[front_Index] = 0;
			cheeseBlock[back_Index] = 0;
			// ������ 0�� �� ���� ������ �ʿ䰡 �����Ƿ� �ε��� ����
			back_Index--;
			front_Index++;

			time++; // 
		}

		cout << time << endl;
		 
		testCase--;
	}

	return 0;
}