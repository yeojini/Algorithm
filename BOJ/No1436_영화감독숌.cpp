/*
���� : 666,1666,2666,3666 �̷��� ���������´�
�Է� : ���� N(10000���� �۰ų� ���� �ڿ���)
��� : N��°��ȭ�� ���� �� ��

[����]
�Է�) 2 
���) 1666
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	int N=0;
	int res = 666;
	int cnt = 0;
	cin >> N;
	vector<int> v;
	vector<string> v2;
	/*for (int i = 0;; i++) {
		int num = i;
		while (num != 0) {
			if (num % 10 == 6) cnt++;
			else if (cnt >= 3) break;
			else cnt = 0;
			num/= 10;
		}
		if(cnt>=3) v.push_back(i);
		if (v.size() == N) break;
		cnt = 0;
	}*/
	//s.find �� �ִ�... 
	for (int i = 0;; i++) {
		string s = to_string(i);
		if (s.find("666")!=-1) v2.push_back(s);
		//find �� ��ȯ�� : ù���ڰ� ���� index. ã�����ϸ� -1
		if (v2.size() == N) break;
	}
	cout << v2[N - 1];

	return 0;
}