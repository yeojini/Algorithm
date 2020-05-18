# 문제
백준 BOJ 1260번 DFS와 BFS

# 코드
```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[1001];
bool check[1001];
//각 정점의 방문 여부
bool discovered[1001] = { false };

//방문할정점 목록을 유지하는 큐
queue<int> q;

//정점의 방문 순서
vector<int> order;

void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	cout << x << ' '; //방문한 점 출력
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start) {

	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		//here 방문
		cout << here << " ";
		for (int i = 0; i < a[here].size(); i++) {
			int there = a[here][i];
			//처음 보는 정점이면 방문 목록에 삽입
			if (discovered[there]==false) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
}
int main() {

	int n, m, s;//n:정점 개수, m:간선 개수 s:시작 번호
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v); //양방향 간선이니까 각각 넣어줌
		a[v].push_back(u);
	}

	//작은 수부터 선택되도록 오름차순 sorting
	for (int i = 1; i < n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(s);
	cout << "\n";
	bfs(s);
}
```
