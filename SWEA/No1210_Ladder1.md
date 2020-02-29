# 1. 풀이

1. **도착점**을 찾는다
2. 좌우에 길이 있는지 살펴보고 없으면 위로 간다
3. 좌우에 길이 있다면 끝까지 이동한 뒤 위로 간다

# 2. 코드
```
    #include <iostream>
    using namespace std;
    /*
    거꾸로 올라가보자!!
    
    */
    int map[101][101];
    int idx=0;
    
    void solve(int x, int y) {
    	while (x >= 0) {
    		x--;
    		if (map[x][y - 1] == 1) { //왼쪽에 길이 있으면
    			do {
    				y--; //왼쪽으로 이동
    			} while (map[x][y - 1] == 1);
    		}
    		else if (map[x][y + 1] == 1) { //오른쪽에 길이 있으면
    			do {
    				y++; //오른쪽으로 이동
    			} while (map[x][y + 1] == 1);
    		}
    	}
    	cout << "#" << idx << " " << y << "\n";
    }
    
    int main() {
    	for (int tc = 1; tc < 11; tc++) {
    		map[100][100] = { 0, };
    		int fx=0, fy=0;
    		cin >> idx;
    		for (int i = 0; i < 100; i++) {
    			for (int j = 0; j < 100; j++) {
    				cin >> map[i][j];
    				//도착점 찾으면 그때의 i,j 저장
    				if (map[i][j] == 2) fx = i, fy = j;
    			}
    		}
    		solve(fx, fy);
    	}
    
    	return 0;
    }
```
# 3. 피드백