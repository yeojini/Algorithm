#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string str;
		stack<char> stk;
		bool chk=true;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				stk.push(str[j]);
			}
			else if (str[j]==')') {
				if (stk.empty()) {
					chk = false;
					break;
				}
				stk.pop();
			}
		}
		if (stk.empty()&&chk) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}