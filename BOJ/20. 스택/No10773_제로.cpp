#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	int sum = 0;
	stack<int> stk;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		
		if (tmp == 0) {
			stk.pop();
		}
		else stk.push(tmp);
	}
	
	while (!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}
	cout << sum << endl;
	return 0;
}