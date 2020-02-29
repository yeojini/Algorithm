# 1. 풀이

- 연락이 넘어가는 주기 → queue 사용.
- 100명의 사람이 100명의 사람에게 연락할수 있으므로 이차원배열 call[101][101] 선언
- from, to 입력받으면 call[from][to] 가 1이 된다
- 방문했는지 안했는지 check 하는 visited[101] 선언. visited[i]==true 면 방문해야할 큐에 삽입하지 않는다.
- 가장 마지막 주기에 연락받는 사람들을 저장하는 queue 선언. 연락책 queue 가 비면 while 문을 탈출하게 되어 다음으로 넘어가게. while 문 한 사이클이 돌때마다 초반에  연락받는 queue 를 초기화해줘야한다.

# 2. 코드
```
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <string.h>
    using namespace std;
    
    int call[101][101];
    bool visited[101] = {false,};
    
    int res;
    queue<int> f;
    queue<int> t; //마지막에 연락받는 애들
    
    int solve(int n) {
    	int max = 0;
    	visited[n] = true;
    	f.push(n);
    	while (!f.empty()) {
    		int f_size = f.size(); // 한 사이클에 연락할 대상의 수
    		while (!t.empty()) t.pop(); //연락대상 clear
    
    		//각 연락책에 대해 연락대상을 연락책 queue 에 push
    		for (int i = 0; i < f_size; i++) {
    
    			int f_front = f.front(); //연락책을 변수에 저장하고
    			f.pop(); //큐에서 제거
    			t.push(f_front); //동시에 연락받은 애들 
    			
    			for (int j = 0; j < 101; j++) {
    				if (call[f_front][j] == 1 && !visited[j]) { //연락가능하고 연락한적 없으면
    					visited[j] = true; //방문했다고 하고
    					f.push(j);//연락할 사람에 추가
    				}
    			}
    		} //한사이클 끝
    	}//연락가능한 사람이 없으면 queue f 가 비게 되어 while 문 탈출
    		
    
    	while (!t.empty()) {
    		int t_front = t.front();
    		t.pop();
    		if (t_front > max) max = t_front;
    	}
    	
    	return max;
    }
    
    int main() {
    	int length;
    	int start;
    	for (int tc = 1; tc <11; tc++) {
    
    		memset(call, 0, sizeof(call));
    		memset(visited, 0, sizeof(visited));
    
    		cin >> length >> start;
    		
    		for (int i = 0; i < length/2; i++) {
    			int from;
    			int to;
    			cin >> from>>to;
    			call[from][to] = 1;
    		}
    
    		cout << '#' << tc << ' '<<solve(start) << '\n';
    	}
    	return 0;
    }
```
# 3. 피드백