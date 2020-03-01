#include <iostream>
#include <string>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	int idx;
	int L;
	char c;
	string ss[10] = { "ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN" };

	string line;
	string str;

	cin >> T;

	//getline은 개행문자 읽고 처음에 나오는 개행 문자도 읽음

	for (int tc = 1; tc <= T; tc++) {
		int cnt[10] = { 0, };
		cin >> c;
		cin >> idx;
		cin >> L;
		for (int i = 0; i < L; i++) {
			cin >> str;
			for (int j = 0; j < 10; j++) {
				if (str == ss[j]) {
					cnt[j]++;
					break;
				}
			}

		}
		cout << "#" << tc << "\n";

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << ss[i] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}