# 문제
백준 BOJ 2902번 KMP는 왜 KMP일까?
# 코드
```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {

	string str;
	cin >> str;
	cout << str.substr(0, 1);
	for (int i = 0; i < str.size(); i++) {
		if (str.substr(i, 1) == "-") {
			cout << str.substr(i+1, 1);
		}
	}


	return 0;
}
```
