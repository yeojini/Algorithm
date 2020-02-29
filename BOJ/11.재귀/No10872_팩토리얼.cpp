#include <iostream>
using namespace std;

int pibo(int a) {
	int result = 1;
	for (int i = 1; i <= a; i++) result *= i;
	return result;
}

int main() {

	int N;
	cin >> N;

	cout << pibo(N);

	return 0;
}
