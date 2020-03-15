/*
# 1. 풀이

- 입력받은 모든 x 좌표들 중 연속한 x 좌표를 골라 mid 좌표를 설정한다.
- mid 좌표를 기준으로 왼쪽 인력, 오른쪽 인력을 구한다
- 왼쪽 인력이 더 크면 mid 좌표를 왼쪽 좌표로, 오른쪽 인력이 더 크면 mid 좌표를 오른쪽 좌표로하여 다시 while 수행
- 오른쪽 좌표와 왼쪽 좌표의 오차가 1e-12 이면 break; 하고 result 배열에 값 저장

*/

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int x[10];
int w[10];
double result[10];

double force(int start, int end, double mid) {
	double f = 0;
	for (int i = start; i <= end; i++) {
		f += w[i] / ((x[i] - mid)*(x[i] - mid));
	}
	return f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(10);
	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(x, 0, sizeof(x));
		memset(w, 0, sizeof(w));
		memset(result, 0, sizeof(w));

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> w[i];
		}

		double L, R, fL, fR, mid;

		for (int i = 0; i < N - 1; i++) {
			L = x[i];
			R = x[i + 1];
			while (1) {
				mid = (L + R) / 2.0;
				fL = force(0, i, mid);
				fR = force(i + 1, N - 1, mid);
				(fL > fR) ? (L = mid) : (R = mid);
				if ((R - L) < 1e-12) break;
			}
			result[i] = mid;
		}

		cout << "#" << tc << " ";
		for (int i = 0; i < N - 1; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
