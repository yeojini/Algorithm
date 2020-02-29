# 1. 풀이

# 2. 코드
```
    #include<iostream>
    #include<string.h>
    using namespace std;
     
    int dump;
    int wall[101];
     
     
    int main(void)
    {
        for(int i = 1; i <= 10; i++)
        {
            cin >> dump;
            memset(wall, 0, sizeof(int)*101);
            for (int j = 0; j < 100; j++)
                cin >> wall[j];
            int highest = 0, lowest = 0;
            for (int d = 0; d <= dump; d++) {
                for (int j = 0; j < 100; j++)
                {
                    // 최고점 찾기
                    if (wall[j] > wall[highest]) highest = j;
                    // 최저점 찾기
                    if (wall[j] < wall[lowest]) lowest = j;
                }
                if ((wall[highest] - wall[lowest]) == 1 || (wall[highest] - wall[lowest]) == 0) break;
                if (d == dump) break;
                wall[highest]--;
                wall[lowest]++;
            }
     
            cout << '#' << i << ' ' << wall[highest] - wall[lowest] << '\n';
        }
     
        return 0;
    }
```

# 3. 피드백
```
    ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
```
요거 main함수에 넣으면 입출력 속도 빨라짐