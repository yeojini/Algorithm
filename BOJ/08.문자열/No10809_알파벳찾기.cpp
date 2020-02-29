/*
문제 : 알파벳 소문자로 이루어진 단어 s. 길이 100 이하
a~z 에 대하여 s에 포함되어 있으면 처음 등장하는 위치 출력,
포함되어 있지 않다면 -1을 공백으로 구분하여 출력


*/


#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cin >> s;

	char arr[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int loc[26]; //알파벳 당 처음 등장하는 위치를 저장하는 배열
	for (int i = 0; i < 26; i++) {
		bool flag = false; //일치 하는 문자를 발견하면 true 로 바뀜
		for (int j = 0; j < s.size(); j++) {
			if (arr[i]==s[j]) {
				loc[i] = j;
				flag = true;
				break; 
				//일치하는 문자를 발견하면 브레이크 해서 다음에 똑같은 문자가 나와 값이 변경되는걸 막아야함
			}
		}
		//일치하는 문자를 발견 못했으면 -1
		if(!flag) loc[i] = -1;
	}

	for (int i = 0; i < 26; i++) {
		cout << loc[i] << " ";
	}



	return 0;
}