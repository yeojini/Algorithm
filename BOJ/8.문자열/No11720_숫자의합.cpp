/*
���� : ������� ���� N���� ���ڸ� ��� ���� ���

�Է� : ù°�� N(1~100) ��°�� ���� N ��

��� : �Է����� �־��� ���� N���� ��

*/

#include <iostream>
#include <string>
using namespace std;

int arr[100];

int main() {

	int N;
	cin >> N;
	int sum=0;
	string nums;
	cin >> nums;
	
	for (int i = 0; i < N; i++) {
		sum += nums[i]-48;
	}

	cout << sum;


	return 0;
}