/*
���� : 
���ڿ� s �Է� �ް� �� ���ڸ� R �� �ݺ��� ���ο� ���ڿ� P�� �����
s ���� : 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:
s�� ���̴� 1~20

�Է� :
ù°�� - ���̽� ���� T(1~1000)
��°�� ~ �� ���̽��� ���� �ݺ�Ƚ��,���ڿ� s

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