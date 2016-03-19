// 12121527 이성온

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int testCase = 0;

	cin >> testCase;
	while (testCase != 0) {
		double min_most = 10; // 가장 작은 값
		double max_most = 0;  // 가장 큰 값
		double min_next = 10; // 두번째로 작은 값
		double max_next = 0;  // 두번째로 큰 값
		double adjust_average = 0; // 조정평균
		double cut_average = 0;    // 절사평균
		double sum = 0;		  // 총합
		double temp = 0;      // 입력하는 수
		int inputNum = 0;     // 입력하는 숫자의 개수
		int tempInputNum = 0; // 임시 입력하는 숫자의 개수

		cin >> inputNum;
		tempInputNum = inputNum;
		while (inputNum != 0) {
			cin >> temp;

			sum = sum + temp;

			// 가장 큰 값
			if (max_most < temp) {
				max_most = temp;
			}
			// 가장 작은 값
			if (min_most > temp) {
				min_most = temp;
			}

			// 두번째로 큰 값
			if (max_next < temp && max_most > temp) {
				max_next = temp;
			}
			// 두번째로 작은 값
			if (min_next > temp && min_most < temp) {
				min_next = temp;
			}
			
			inputNum--;
		}
		
		inputNum = tempInputNum;
		// 절사평균
		sum = sum - (max_most + min_most); // 가장 큰 값, 가장 작은 값을 뺀 총합 구하기
		cut_average = sum / (inputNum - 2);
		cout.setf(ios::showpoint);	// 소수점자리에 0이 나와도 표현
		cout.precision(4);			// 가장 큰 자리 수부터 4째 자리까지 소수점 표현
		cout << cut_average << " ";

		// 보정평균, 조정평균
		sum = sum - (max_next + min_next) + (max_most + min_most); // 두번째로 큰 값, 두번째로 작은 값을 뺀 총합 구하기 
		adjust_average = sum / (inputNum - 2);
		cout.setf(ios::showpoint);
		cout.precision(4);
		cout << adjust_average << endl;

		testCase--;
	}

	return 0;
}