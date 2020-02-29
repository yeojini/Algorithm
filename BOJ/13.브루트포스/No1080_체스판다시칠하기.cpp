/*
문제 : M*N 보드판 잘라서 8*8 크기 체스판으로
체스판은 맨왼쪽 위가 흰색,검은색 인 경우 2개
다시 칠해야하는 정사각형의 최소 개수

입력 : 
1-N,M (8보다 크거나 같고 50보다 작거나 같은 자연수)
2-N개의 줄에 보드의 각 행의 상태 B(검정)/W(흰색)
출력 : 다시 칠해야하는 정사각형개수의 최소값

[예제] 
입력)
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
출력)
1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> board;

int cal(int row, int col, char color1, char color2) {
	int nx = row + 8;
	int ny = col + 8;
	int cnt = 0;
	for (int i = row; i < nx; i++) {
		for (int j = col; j < ny; j++) {
			//맨하탄 거리 측정법
			//시작점으로부터 거리가 짝수일 때
			if ((i - row + j - col) % 2 == 0) {
				if (board[i][j] != color1) cnt++;
			}
			//거리가 홀수일 때
			else {
					if (board[i][j] != color2) cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int N=0, M=0;
	cin >> N >> M;
	string tmp;
	int min = 100;
	
	for (int i = 0; i < N; i++) {
			cin >> tmp;
			board.push_back(tmp);
	}

	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++) {
			int min1 = cal(i, j, 'W', 'B'); //흰검흰검으로 시작시
			int min2 = cal(i, j, 'B', 'W'); //검흰검흰으로 시작시
			if (min1 < min) min = min1;
			if (min2 < min) min = min2;
		}
	}
	cout << min;
	return 0;
}