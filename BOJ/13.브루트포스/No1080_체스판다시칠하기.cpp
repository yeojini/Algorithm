/*
���� : M*N ������ �߶� 8*8 ũ�� ü��������
ü������ �ǿ��� ���� ���,������ �� ��� 2��
�ٽ� ĥ�ؾ��ϴ� ���簢���� �ּ� ����

�Է� : 
1-N,M (8���� ũ�ų� ���� 50���� �۰ų� ���� �ڿ���)
2-N���� �ٿ� ������ �� ���� ���� B(����)/W(���)
��� : �ٽ� ĥ�ؾ��ϴ� ���簢�������� �ּҰ�

[����] 
�Է�)
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
���)
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
			//����ź �Ÿ� ������
			//���������κ��� �Ÿ��� ¦���� ��
			if ((i - row + j - col) % 2 == 0) {
				if (board[i][j] != color1) cnt++;
			}
			//�Ÿ��� Ȧ���� ��
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
			int min1 = cal(i, j, 'W', 'B'); //���������� ���۽�
			int min2 = cal(i, j, 'B', 'W'); //����������� ���۽�
			if (min1 < min) min = min1;
			if (min2 < min) min = min2;
		}
	}
	cout << min;
	return 0;
}