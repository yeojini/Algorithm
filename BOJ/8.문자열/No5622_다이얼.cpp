/*
���� : ����� 0987654321 ���� �ϳ� ������ ó�� ��ġ�� ���ư�
���� 1�� �ŷ��� 2�� �ʿ�.���� 1 �þ���� 1�ʾ� ���ɸ�
�� ���ĺ��� �ش� �ϴ� ���ڷ� ��ȯ
�Է� : ���ĺ�  �빮�� �ܾ�. (���� :2~15)
��� : ���̾��� �ɸ� ���� �ʿ��� �ð�

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string s;
	vector<int> v;
	int res=0;

	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'C') v.push_back(2);
		else if ('D' <= s[i] && s[i]<='F') v.push_back(3);
		else if ('G' <= s[i] && s[i] <= 'I') v.push_back(4);
		else if ('J' <= s[i] && s[i] <= 'L') v.push_back(5);
		else if ('M' <= s[i] && s[i] <= 'O') v.push_back(6);
		else if ('P' <= s[i] && s[i] <= 'S') v.push_back(7);
		else if ('T' <= s[i] && s[i] <= 'V') v.push_back(8);
		else if ('W' <= s[i] && s[i] <= 'Z') v.push_back(9);
		
	}
	res = v[0]+1;
	for (int i = 1; i < v.size(); i++) {
		switch (v[i]){
			case 2:
				res += 3;
				break;
			case 3:
				res += 4;
				break;
			case 4:
				res += 5;
				break;
			case 5:
				res += 6;
				break;
			case 6:
				res += 7;
				break;
			case 7:
				res += 8;
				break;
			case 8:
				res += 9;
				break;
			case 9:
				res += 10;
				break;
		}
	}
	cout << res;



	return 0;
}