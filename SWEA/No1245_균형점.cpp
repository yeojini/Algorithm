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
