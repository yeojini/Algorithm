/*
���� : ���ĺ� ��ҹ��ڷ� �� �ܾ�. �� �ܾ�� ���� ���� ���� ���ĺ� ���
��ҹ��� ���� X
�Է� : ���ĺ� ��ҹ��ڷ� �̷���� �ܾ�
��� : ���� ���� ���� ���ĺ��� �빮�ڷ� ���. ���� ���� ���� ���ĺ��� �������� ? ���

*/

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

	vector<char> v; //���ڿ� ���� ���ĺ�
	int cnt[26] = { 0, };//���ĺ��� �� �����ϴ� �迭
	string s;
	char res=' ';
	
	cin >> s;

	//�� �빮�ڷ� �ٲٱ� 
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32; // �빮�ڴ� �ҹ��ں��� 32 �۴�
			v.push_back(s[i]);
		}
	}

	//�ߺ�����
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	//���ĺ� �� ī��Ʈ

	//�� ���ĺ��� ���Ͽ�
	for (int i = 0; i < v.size(); i++) {
		//���ڿ� ���� �� ������ cnt �� ����
		for (int j = 0; j < s.size(); j++) {
			if (v[i] == s[j]) cnt[s[j] - 65]++;
		}
	}

	int maxidx=0;
	int maxcnt=0;
	
	//�ִ� �� ���� ã��
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > maxcnt) {
			maxcnt = cnt[i];
			maxidx = i;
		}
	}

	int count = 0;
	for (int i = 0; i < 26; i++) {
		//�󵵰� ���� ���ڰ� �����ϸ�
		if (cnt[i]==maxcnt) {
			count++; //ī��Ʈ�� ������Ų��
		}
	}
	//������ �󵵰� ���� ���� 2�� �̻� �ִٸ�
	if (count > 1) res = '?';
	else res = maxidx+65;
	cout << res;




	return 0;
}