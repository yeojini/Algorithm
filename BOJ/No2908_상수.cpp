/*
���� : A,B �� �Ųٷ� ���� �� �� ū ��������ض�
�Է� : �������� ���ڸ� �� A,B. 0 ���� X 

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	string A;
	string B;
	cin >> A;
	cin >> B;

	vector<char> a;
	vector<char> b;
	bool flag = true;

	for (int i = 2; i >= 0; i--) {
		a.push_back(A[i]);
		b.push_back(B[i]);
	}

	for (int i = 0; i < 3; i++) {
		if (a[i] > b[i]) {
			flag = true; 
			break;
		}
		else if (b[i] > a[i]) {
			flag = false;
			break;
		}
	}
	 
		for (int i = 0; i < 3; i++) {
			if (!flag) cout << b[i];
			else cout << a[i];
		}
	
	return 0;
}