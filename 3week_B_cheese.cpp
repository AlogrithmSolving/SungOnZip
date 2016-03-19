// 12121527 이성온

#include<iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int testCase = 0;

	cin >> testCase;
	while (testCase != 0) {
		int cheeseBlock[1000] = { 0, }; // 치즈개수가 저장된 배열
		int width = 0, height = 0;		// 주어진 치즈 블록의 너비, 높이
		int left_Cheese = 0, right_Cheese = 0; // 해당 인덱스의 좌, 우 치즈
		int min_Cheese = 0;		    // 양 옆 치즈중 작은 수의 치즈
		int temp_Cheese = 0;		// 해당 인덱스의 치즈를 제거작업을 한 뒤, 다음 인덱스의 치즈에서 이전 인덱스의 작업 이전의 치즈 양을 저장
		int time = 0;				// 쥐들이 모든 치즈를 먹는데 걸리는 시간
		int sum = 0;				// 남은 치즈의 총량
		int front_Index = 0, back_Index = 0; // 남은 치즈 중 첫번째, 마지막 위치

		cin >> width >> height;

		// 치즈 개수 입력, 총 치즈의 개수 구하기
		for (int i = 0; i < width; i++) {
			cin >> cheeseBlock[i];
			sum = sum + cheeseBlock[i];
		}

		// 인덱스이므로 너비 -1
		back_Index = width - 1;
		
		// 치즈의 총합이 0이 될때 까지 반복문 계속
		while (sum != 0) {
			if (sum == 0) { break; }

			left_Cheese = cheeseBlock[front_Index];

			// 첫번째와 마지막 인덱스의 치즈는 한순간에 사라지므로 반복문 이후에 작업
			for (int k = front_Index + 1; k < back_Index; k++) {
				if (cheeseBlock[k] == 0) {
					continue;
				}
				right_Cheese = cheeseBlock[k + 1]; 

				// 양쪽의 치즈 중 최소개수 구하기
				if (left_Cheese >= right_Cheese) {
					min_Cheese = right_Cheese;
				}
				else if (left_Cheese < right_Cheese) {
					min_Cheese = left_Cheese;
				}
				
				temp_Cheese = cheeseBlock[k]; // 해당 블록의 치즈에 대한 계산 후 다음 인덱스의 치즈 계산에 필요하므로 개수저장

				// 치즈 빼기
				// 양 옆 치즈 중 최소 개수의 치즈만큼 남거나
				if (cheeseBlock[k] > min_Cheese) {
					sum = sum - (cheeseBlock[k] - min_Cheese);
					cheeseBlock[k] = min_Cheese;
				}
				// 최소 개수의 치즈가 해당 인덱스의 치즈보다 많을 경우 하나의 치즈만 먹음
				else {
					sum = sum - 1;
					cheeseBlock[k] = cheeseBlock[k] - 1;
				}

				left_Cheese = temp_Cheese;
			}
			// 배열 한바퀴 돈 뒤 처음과 끝 인덱스의 치즈 제거
			if (front_Index != back_Index) {
				sum = sum - (cheeseBlock[front_Index] + cheeseBlock[back_Index]);
			}
			// 시작 인덱스, 끝 인덱스가 같은 경우 중복되어 계산되므로 하나만 빼기
			else {
				sum = sum - cheeseBlock[front_Index];
			}
			// 첫번째, 마지막 인덱스 치즈는 항상 바로 0이 됨
			cheeseBlock[front_Index] = 0;
			cheeseBlock[back_Index] = 0;
			// 개수가 0이 된 곳은 접근할 필요가 없으므로 인덱스 변경
			back_Index--;
			front_Index++;

			time++; // 
		}

		cout << time << endl;
		 
		testCase--;
	}

	return 0;
}