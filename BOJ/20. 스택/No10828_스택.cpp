#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int s[10001]; //명령의 개수 N은 1~10000
int top = -1;
//스택의 가장 위에 있는 정수 출력. 없으면 -1 출력
//top이 어디있는지 알려주면서 스택이 어디까지 차 있는지 저장한다.

void push(int x) {
	s[++top] = x;
}

//스택에 가장 위에 있는 정수 빼고 그 수를 출력. 들어있는 정수가 없으면 -1 출력
void pop() {
	if (top==-1) {
		cout << -1 << endl;
	}
	else
	{
		cout << s[top] << endl;
		s[top--] = 0;
	}

}

int empty() {
	if (top == -1) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char str[10];
		cin >> str;
		//srcmp(A,B) : A,B 가 같으면 0, A 가 크면 1, B 가 크면 -1 반환
		if (strcmp(str, "push") == 0) {
			//입력받을 숫자
			int tmp;
			cin >> tmp;
			push(tmp);
		}
		else if (strcmp(str, "pop") == 0) {
			pop();
		}
		else if (strcmp(str, "size") == 0) {
			if (top == -1) cout << 0 << endl;
			else cout << top+1 << endl;
		}
		else if (strcmp(str, "empty") == 0) {
			if (top != -1) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else if (strcmp(str, "top") == 0) {
			if (top == -1) cout << -1 << endl;
			else cout << s[top] << endl;

		}
	}


	return 0;
}