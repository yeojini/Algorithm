/*
���� : ���ĺ� �ҹ��ڷ� �̷���� �ܾ� s. ���� 100 ����
a~z �� ���Ͽ� s�� ���ԵǾ� ������ ó�� �����ϴ� ��ġ ���,
���ԵǾ� ���� �ʴٸ� -1�� �������� �����Ͽ� ���


*/


#include <iostream>
#include <string>
using namespace std;

int main() {

	string s;
	cin >> s;

	char arr[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int loc[26]; //���ĺ� �� ó�� �����ϴ� ��ġ�� �����ϴ� �迭
	for (int i = 0; i < 26; i++) {
		bool flag = false; //��ġ �ϴ� ���ڸ� �߰��ϸ� true �� �ٲ�
		for (int j = 0; j < s.size(); j++) {
			if (arr[i]==s[j]) {
				loc[i] = j;
				flag = true;
				break; 
				//��ġ�ϴ� ���ڸ� �߰��ϸ� �극��ũ �ؼ� ������ �Ȱ��� ���ڰ� ���� ���� ����Ǵ°� ���ƾ���
			}
		}
		//��ġ�ϴ� ���ڸ� �߰� �������� -1
		if(!flag) loc[i] = -1;
	}

	for (int i = 0; i < 26; i++) {
		cout << loc[i] << " ";
	}



	return 0;
}