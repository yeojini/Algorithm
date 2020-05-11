# 배열 초기화

`memset(wall, 0, sizeof(wall));`

# 큐의 초기화

`while(!q.empty()) q.pop();`

# 처리 시간 빠르게

```c
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
```

# 소수점 지정

```c

cout.setf(ios::fixed);
cout.precision(6);
```

# 벡터 중복 제거

- sort 후 해야함
- `v.erase(unique(v.begin(), v.end()), v.end());`

# 아스키 코드 응용

- 'A'-65 = 0 = 'a' - 97 = '0' - 48

# 배열 응용

- 열의 합, 행의 합, 대각선의 합

```cpp
for (int i = 0; i < 100; i++) {
    			for (int j = 0; j < 100; j++) {
    				rowsum[i] += nums[i][j]; //열의합
    				colsum[i] += nums[j][i]; //행의합
    			}
    			digsum += nums[i][i];//왼쪽위부터오른쪽아래 대각선
    			digsum2 += nums[i][99 - i];//오른쪽위부터왼쪽아래대각선
    		}
```

# 회문

```cpp
//가로
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8-len+1; j++) {
				bool flag = true; //회문인지
				for (int k = 0; k < len / 2; k++) {
					if (map[i][j + k] != map[i][len + j - k - 1]) {
						//회문이 아니면
						flag = false;
						break;
					}
				}
				if (flag) {
					cnt++;
				}
				
			}
		}
```

# Map

```cpp
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

for (int z = 0; z < 4; z++) {
    			int nx = x + dx[z];
    			int ny = y + dy[z];
    			if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16) continue;
          //~구현~
}
```
