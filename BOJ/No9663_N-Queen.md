# 문제
백준 BOJ 9664번 N-Queen C++

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N이 주어진다. (1 ≤ N < 15)

## 출력

첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c08ff28c-aa62-4d74-9389-2f9800ab4ac6/Untitled.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c08ff28c-aa62-4d74-9389-2f9800ab4ac6/Untitled.png)

    

N이 14까지밖에 없어서 작아보이지만 완탐을 돌리게 될 경우 N^2^N 이 되므로 절대 안된다. -> 
# 
```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    
    //board[열]=행
    int board[15];
    
    bool isPossible(int row) {
    	//이미 비치된 퀸과 같은 줄에 있거나, 대각선에 있을 경우 배치될 수 없다.
    	//첫줄(row=0)은 일단 비치
    	for (int i = 0; i < row; i++) {
    		if (board[row] == board[i] || abs(board[row] - board[i]) == (row - i)) return false;
    	}
    	return true;
    }
    
    void game(int row, int n, int* count) {
    	if (row == n) {
    		(*count)++;
    		return;
    	}
    	for (int i = 0; i < n; i++) {
    		board[row] = i;
    		if (isPossible(row) == true) {
    			game(row+1, n, count);
    		}
    	}
    }
    int main() {
    	int n;
    	cin >> n;
    	int count = 0;
    	game(0, n, &count);
    	//count 값을 함수에서 반환 받아야하므로 &count
    	cout << count << "\n";
    	return 0;
    }
```

# 풀이

1. 퀸을 놓을 수 있는 경우 다음 행(row+1)으로 넘어가고 재귀호출.끝까지  다 넣으면(row==n) count++ 
2. board[row]=i
3. 이미 비치된 퀸의 직선, 대각선에 다음 퀸을 놓을 수 없다 + 한 줄에 퀸은 하나다
4. 현재 퀸의 좌표가 (a,b) 일때 다음 대각선에 오는 퀸의 좌표가 (c,d) 라면 

|a-c| ≠ |b-d|

if (board[row] == board[i] || abs(board[row] - board[i]) == (row - i)) 

# 기억할 점

- main에서 함수에 값을 전달하고, 받을 때 & 붙이기
- 함수의 매개변수에서는 * 로
- 그 매개변수를 함수 안에서 쓸때는 * 붙여서 쓰기
- row++ 이 아니라 row+1.. 다음 재귀 호출 시 그 매개변수에 row+1 이 그대로 들어가는 거니까 row==n 이게 실은 (row+1)=n 이 형태니까 암튼 알아들어라대충

# 고민했던 점

- if (board[row] == board[i] || abs(board[row] - board[i]) == (row - i)) return false;
