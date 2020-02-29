/*

동적 계획법 : 큰 문제를 작은 문제로 나눠서 값들을 저장해 다시사용
botton-up 방식. n이 0일때와 n이 1일때는 고정되어 있으니까
나머지 값을 다른 값으로 초기화 하여 조건문에서 n이 0,1 이 아닌 경우 

int fibonacci(int n) {
	if (n == 0) {
		printf("0");
		return 0;
	} else if (n == 1) {
		printf("1");
		return 1;
	} else {
		return fibonacci(n‐1) + fibonacci(n‐2);
	}
}

fibonacci(N) 호출 시 0과 1이 각각 몇번 출력되는지

N은 40보다 작거나 같은 자연수 또는 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N; //T:테스트 케이스 수, N: 각 테스트에서 fibbo 안의 파라미터 N 입력
int num[41][2] = { {1,0},{0,1} }; //초기화
//0~40 수를 저장하기 위해 41 크기의 배열
//n이 0일때는 0을 1번, 1을 0번 계산하고
//n이 1일때는 0을 0번, 1을 1번 계산한다
vector<int> Ns;

int main() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> N;
		Ns.push_back(N);
	}
	
			for (int i = 2; i <= 40; i++) { //n이 0일때,1일때는 계산되어 있으니까(메모리제이션)
				num[i][0] = num[i - 1][0] + num[i - 2][0];
				num[i][1] = num[i - 1][1] + num[i - 2][1];
			}
			for (int i = 0; i < Ns.size(); i++) {
				cout << num[Ns.at(i)][0] << " " << num[Ns.at(i)][1] << endl;
	}
	
	
	return 0;
}
