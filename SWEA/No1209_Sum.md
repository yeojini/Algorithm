# 1. 풀이

# 2. 코드
```
    /*
    문제 : 100*100 2차원 배열
    각 행의 합, 각 열의 합, 각 대각선의 합 중 최댓값
    
    
    */
    
    #include <iostream>
    using namespace std;
    int main() {
    	int tc,idx,tmp=0;
    	for (int tc = 1; tc < 11;tc++) {
    		cin >> idx;
    		int nums[100][100] = { 0, };
    		int max = 0;
    		int rowsum[100] = { 0, };
    		int colsum[100] = { 0, };
    		int digsum = 0,digsum2 = 0;
    		for (int i = 0; i < 100; i++) {
    			for (int j = 0; j < 100; j++) {
    				cin >> tmp;
    				nums[i][j] = tmp;
    			}
    		}
        //값 입력 받아 배열에 채워넣기
    
    		for (int i = 0; i < 100; i++) {
    			for (int j = 0; j < 100; j++) {
    				rowsum[i] += nums[i][j]; //열의합
    				colsum[i] += nums[j][i]; //행의합
    			}
    			digsum += nums[i][i];//왼쪽위부터오른쪽아래 대각선
    			digsum2 += nums[i][99 - i];//오른쪽위부터왼쪽아래대각선
    		}
    
    		if (max < digsum) max = digsum;
    		if (max < digsum2) max = digsum2;
    		//일단 대각선 2개 중 큰 값을 고르고 그 값을 max 로 함
    
    
    		for (int i = 0; i < 100; i++) {
    			if (max < rowsum[i]) max = rowsum[i];
    			if (max < colsum[i]) max = colsum[i];
    		}
    		
    		cout << "#" << idx << " " << max<<"\n";
    
    	}
    
    
    	return 0;
    }
```

# 3. 피드백