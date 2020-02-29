/*
문제 : 
문자열 s 입력 받고 각 문자를 R 번 반복한 새로운 문자열 P를 만든다
s 에는 : 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:
s의 길이는 1~20

입력 :
첫째줄 - 케이스 개수 T(1~1000)
둘째줄 ~ 각 케이스에 대한 반복횟수,문자열 s

*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, string> test;
vector<pair<int,string>> tests;

int main() {

	int T;
	cin >> T;
	int tmp;
	string s;
	
	for (int i = 0; i < T; i++) {
		cin >> test.first >> test.second;
		tests.push_back(test);
	}

	for (int i= 0; i < T; i++) {
		string res = "";
		for (int k = 0; k < tests[i].second.size(); k++) {
			for (int j = 0; j < tests[i].first; j++) {
				res += tests[i].second[k];
			}
		}
		cout << res << endl;
	}



	return 0;
}