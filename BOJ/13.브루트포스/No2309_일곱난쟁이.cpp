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
	sort(arr, arr + n); //�������� ����
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - arr[i] - arr[j] == 100) { //9���� 7�� �̴°� 9���� 2�� �̴°�
				for (int k = 0; k < n; k++) {
					if (i == k || j == k) continue;//2���� �����ϰ� ������ �ֵ鸸 cout
					cout << arr[k] << "/n";
				}
				return 0;
			}
		}
	}
	return 0;
}