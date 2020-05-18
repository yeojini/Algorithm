#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
pair<int, int> person;
int Rank[50];
int N;

void go() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i].second > v[j].second && v[i].first > v[j].first) {
				Rank[j]++;//자신보다 키와 몸무게가 큰 사람이 있을 때만 등수를 높인다.
				
			}
		}
		
	}


}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		pair<int, int> person;
		cin >> person.first >> person.second;
		v.push_back(person);
	}

	go();

	//go();
	
	for (int i = 0; i < N; i++) {
		cout <<Rank[i]+1<<endl;
	}
	return 0;
}
