/*
���� : ���ڿ� ���� �ܾ� ����. ���ڿ��� �հ� �ڿ� ������ ���� ���� �ִ�
�Է� : ���� ��ҹ���,����� �̷���� ���ڿ�
��� : �ܾ��� ���� ���
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	
	string s;
	//cin >> s; ���� �����ؼ� �Է� ������
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