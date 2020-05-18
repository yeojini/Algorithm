/*
문제 : 문자열 내의 단어 세기. 문자열의 앞과 뒤에 공백이 있을 수도 있다
입력 : 영어 대소문자,띄어쓰기로 이루어진 문자열
출력 : 단어의 개수 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	
	string s;
	//cin >> s; 공백 포함해서 입력 못받음
	getline(cin, s);
	int cnt = 1;

	if (s[0] == ' ') cnt = 0;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			cnt++;
		}
	}
	if (s[(s.size() - 1)] == ' ') cnt--;
	cout << cnt;

	return 0;
}
