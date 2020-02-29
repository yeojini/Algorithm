/*
문제 : 알파벳 대소문자로 된 단어. 이 단어에서 가장 많이 사용된 알파벳 출력
대소문자 구분 X
입력 : 알파벳 대소문자로 이루어진 단어
출력 : 가장 많이 사용된 알파벳을 대문자로 출력. 가장 많이 사용된 알파벳이 여러개면 ? 출력

*/

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

	vector<char> v; //문자열 안의 알파벳
	int cnt[26] = { 0, };//알파벳별 빈도 저장하는 배열
	string s;
	char res=' ';
	
	cin >> s;

	//다 대문자로 바꾸기 
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32; // 대문자는 소문자보다 32 작다
			v.push_back(s[i]);
		}
	}

	//중복제거
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	//알파벳 별 카운트

	//각 알파벳에 대하여
	for (int i = 0; i < v.size(); i++) {
		//문자열 안의 각 문자의 cnt 를 센다
		for (int j = 0; j < s.size(); j++) {
			if (v[i] == s[j]) cnt[s[j] - 65]++;
		}
	}

	int maxidx=0;
	int maxcnt=0;
	
	//최대 빈도 문자 찾기
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > maxcnt) {
			maxcnt = cnt[i];
			maxidx = i;
		}
	}

	int count = 0;
	for (int i = 0; i < 26; i++) {
		//빈도가 같은 문자가 존재하면
		if (cnt[i]==maxcnt) {
			count++; //카운트를 증가시킨다
		}
	}
	//문자의 빈도가 같은 것이 2개 이상 있다면
	if (count > 1) res = '?';
	else res = maxidx+65;
	cout << res;




	return 0;
}