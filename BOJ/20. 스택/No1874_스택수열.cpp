/*
코드 똑같고 결과도 잘 나오는데 오ㅐ 틀렸다고 하는거야 BOJ ??!!?

1. 큐를 선언하여 원하는 순서를 선언한 큐에 넣습니다.

2. 큐의 front에 있는 숫자에 대해 먼저 처리해줍니다.

i) num이 해당 숫자가 될 때까지 +

ii) 해당 숫자에 대해서 처리했으므로 큐와 스택 pop을 진행하고 -

3. 이후에는 반복문 내에서 나머지 숫자들을 아래와 같은 세가지 경우에 대해 처리해줍니다.

i) 스택이 비었거나 현재 원하는 숫자 > 스택의 top 일 경우

ii) 현재 원하는 숫자 == 스택의 top

iii) 현재 원하는 숫자 < 스택의 top

4. 3번을 진행한 후 불가능한 경우이면 "NO"를 출력하고 가능한 경우이면 결과 문자열을 출력해줍니다.

출처 : https://jaimemin.tistory.com/819
*/

#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;
	stack<int> stk;
	string str;
	bool isNo = false;

	//수열 입력
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	int cnt = 1;

	//첫번째 값 처리
	for (int i = 0; i < q.front(); i++) {
		stk.push(cnt++);
		str += '+';
	}

	str += '-';
	q.pop();
	stk.pop();
	

	//두번째 값 부터
	while (1) {
		//입력된 수열 완성 시
		if (q.empty()) {
			break;
		}
		//이번에 찾을 숫자
		int cur = q.front();

		//스택이 비어있거나 스택의 top이 찾을 숫자보다 작으면
		if (stk.empty() || stk.top() < cur) {
			//스택에 다음 숫자 추가
			stk.push(cnt++);
			str += '+';
		}
		//스택 꼭대기의 숫자가 찾을 숫자라면
		else if (stk.top() == cur) {
			stk.pop();
			q.pop();
			str += '-';
		}
		//스택 꼭대기의 숫자가 찾을 숫자보다 크다면
		else if (stk.top() > cur) {
			//불가능
			isNo = true;
			break;
		}
	}
	if (isNo) {
		cout << "No\n";
	}
	else {
		for (int i =0 ; i < str.size(); i++) {
			cout << str[i] << '\n';
		}
	}
	
	return 0;
}
