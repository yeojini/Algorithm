#include <iostream>
using namespace std;

int pibo(int a) {
	int result = 0;
	if (a > 0) {
		if (a == 0) result = 0;
		else if (a == 1) result = 1;
		else if (a >= 2) result = pibo(a - 1) + pibo(a - 2);
		return result;
	}
	else return 0;
	
}

int main() {
	int n;
	cin >> n;
	cout << pibo(n);
	
	return 0;
}
