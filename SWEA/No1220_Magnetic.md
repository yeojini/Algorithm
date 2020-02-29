# 1. 풀이

# 2. 코드

    /*
    푸른 자성체의 경우 N극에 이끌리고 붉은 자성체의 경우 S극에 이끌림
    시간이 흐른 뒤에 자성체들이 서로 충돌하여 테이블 위에 남아있는 교착 상태의 개수
    1은 N극 성질을 가지는 자성체를 2는 S극 성질을 가지는 자성체
    테이블의 윗 부분에 N극이 아랫 부분에 S극이 위치
    */

```
    
    #include <iostream>
    using namespace std;
    int main() {
    
    	int map[100][100];
    	int res;
    	int len;
    	for (int test_case = 1; test_case <= 10; test_case++) {
    		res = 0;
    		cin >> len;
    		for (int i = 0; i < 100; i++) {
    			for (int j = 0; j < 100; j++) {
    				cin >> map[i][j];
    			}
    		}//아래 진행 후 오른쪽으로 이동하며 카운트
    		for (int i = 0; i < 100; i++) {
    			bool check = false;
    			for (int j = 0; j < 100; j++) {
    				if (map[j][i] == 0) {
    					continue;
    				}
    				if (check==false&&map[j][i] == 2) { //장애물이 없으면 S 극은 위로 올라간다 
    					continue;
    				}
    				if (map[j][i] == 1) { //아래로 내려가야할 N 극이 있으면
    					check = true;
    				}
    				if (check == true && map[j][i] == 2) {//N극이 있는데 그 아래 S극이 있으면
    					res++;
    					check = false; //다시 카운트 하기 위해 초기화
    
    				}
    			}
    		}
    
    		cout << "#" << test_case << " " << res << "\n";
    	}
    	return 0;
    }
```
# 3. 피드백