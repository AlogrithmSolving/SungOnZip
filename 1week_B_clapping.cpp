// 12121527 이성온

#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int numA = 0, numB = 0, numC = 0; // 숫자 A,B,C
	int sNum = 0, dNum = 0;			  // 시작숫자, 끝숫자
	int testCase = 0;				  // test하는 수
	int clap = 0;					  // 박수

	cin >> testCase; 

	for (int i = 0; i < testCase; i++) {
		clap = 0;
		cin >> numA >> numB >> numC >> sNum >> dNum;

		// 시작 숫자 부터 끝 숫자 까지 탐색
		for (int k = sNum; k <= dNum; k++) {
			int tempK = k;

			// 약수 여부 조사, 약수인게 판명나면 반복문의 처음으로 이동
			if (k%numA == 0 || k%numB == 0 || k%numC == 0) {
				clap++;
				continue;
			}
			
			// 주어진 수가 입력받은 수 A,B,C중 하나를 포함하는지 여부 검사
			while (1) {
				// 1의 자리수에 A,B,C가 있는지 검사
				if (k % 10 == numA || k % 10 == numB || k % 10 == numC) {
					clap++;
					break;
				}
				// 없다면 일의 자리수를 버리고 10으로 나눈 몫으로 다시 검색 시작
				k = k / 10;

				// 주어진 수가 0이 될때까지 반복
				if (k == 0) {
					break;
				}
			} // 숫자 numA,numB,numC가 주어진 수에 들어있는지 여부 체크 끝

			k = tempK;
		}

		cout << clap << endl;
	}
	return 0;
}