/*
문제 : 공백없이 쓰인 N개의 숫자를 모두 합해 출력

입력 : 첫째줄 N(1~100) 둘째줄 숫자 N 개

출력 : 입력으로 주어진 숫자 N개의 합

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