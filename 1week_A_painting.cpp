// 12121527 이성온

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int blankNum;   // 칸 번호_시작번호 시 그대로, 끝번호 시 번호에+1
	int serial;     // 시리얼 번호_1이면 시작번호, -1이면 끝번호
}colorPair;

// colorPair 구조체 비교함수, 오름차순으로 정렬
bool cmp(colorPair A, colorPair B) {
	return A.blankNum < B.blankNum;
} 

int main() {
	std::ios::sync_with_stdio(false);

	int testCase = 0;
	int colorNum = 0, overlap = 0; // 색깔의 수, 덧칠한 색의 수
	
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> colorNum >> overlap;
		
		colorPair a;
		colorPair blank[3050] = { a, };

		// 색깔 범위 입력
		for (int j = 0; j < colorNum*2; j++) {
			//colorPair a;
			// 시작번호 입력 시
			if (j % 2 == 0) {
				cin >> blank[j].blankNum;
				blank[j].serial = 1;
			} 
			// 끝번호 입력 시
			else if(j%2 != 0) {
				cin >> blank[j].blankNum;
				blank[j].blankNum = blank[j].blankNum + 1;
				blank[j].serial = -1;
			}
		}
		// sorting
		sort(blank, blank + (colorNum*2), cmp);

		// 중복된 범위의 수가 나올 때
		for (int p = 0; p < colorNum * 2; p++) {
			if (blank[p].blankNum == blank[p - 1].blankNum && blank[p].serial + blank[p-1].serial == 0 ) {
				blank[p-1].blankNum = 0;	// 두 개의 중복된 범위인 colorPair가 나올 시 앞의 colorPair는 <0,0>으로 초기화
				blank[p-1].serial = 0;
				blank[p].serial = 0;        // 뒤의 colorPair는 기존의 blankNum과 serial은 0으로 초기화 즉 <blankNum, 0>
			} 
		}
		// sorting
		sort(blank, blank + (colorNum * 2), cmp);

		
		int count = 0;
		int startNum = 0;
		for (int k = 0; k < colorNum * 2; k++) {
			// 참고 --> colorPair의 구조 <blankNum, serial>
			// <0,0> 인 colorPair는 무시
			if (blank[k].blankNum == 0) {
				continue;
			}
			// <blankNum, 1> 인 colorPair는 카운팅
			if (blank[k].serial == 1) {
				count++;
				startNum = blank[k].blankNum;
			}
			// <blankNum, -1>인 colorPair은 디카운팅
			else if (blank[k].serial == -1) {
				count--;
				startNum = blank[k].blankNum;
			}
			// 카운팅 횟수가 overlap(=문제에서 K값)과 같고 다음 colorPair의 serial이 0이 아니며, 연속적으로 blankNum이 같지않으면
			// 출력
			// k=1 1~3 4~5 6~9 입력 시 1~9 출력
			// k=3 5~5 5~7 5~5 입력 시 5~5 출력
			// k=2 5~5 5~7 5~5 입력 시 출력없음
			if (count == overlap && blank[k + 1].serial != 0 && blank[k].blankNum != blank[k+1].blankNum) {
				cout << startNum << " " << blank[k + 1].blankNum - 1 << endl;
			}
		}
	}

	return 0;
}
