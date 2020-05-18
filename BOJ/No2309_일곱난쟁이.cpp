#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
const int n = 9;

int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n); //오름차순 정렬
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - arr[i] - arr[j] == 100) { //9명에서 7명 뽑는건 9명에서 2명 뽑는것
				for (int k = 0; k < n; k++) {
					if (i == k || j == k) continue;//2명을 제외하고 나머지 애들만 cout
					cout << arr[k] << "/n";
				}
				return 0;
			}
		}
	}
	return 0;
}