# 1. 풀이

# 2. 코드
```
    #include <iostream>
    #include <iomanip>
    using namespace std;
    
    int max(int a, int b){
        if(a>b) return a;
        else return b;
    }
    
    int main() {
    
    	//왼쪽과 오른쪽 모두 거리 2 이상의 공간이 확보 되야
    	//조망권이 확보된 세대의 수 반환
    	//각 빌딩의 높이는 최대 255
    	
    	int test = 10;
    	int T;
    	int* b;
    	int result=0;
    	
    	for (int i = 1; i <= test; i++) {
    		cin >> T;
            b = new int[T]; // 동적 메모리 할당
    		for (int i = 0; i < T; i++) {
    			
    			int num;
    			cin >> num;
    			b[i] = num;
    		}
            result = 0;
    		for (int i = 2; i < T-2; i++) {
    			if (b[i] >  b[i - 1] && b[i] > b[i - 2]&&b[i] > b[i + 1] && b[i] > b[i +2]) {
                  result += b[i]-max(max(b[i-1],b[i-2]),max(b[i+1],b[i+2]));
                }
    		}
    		cout << "#" << i << " " << result<<"\n";
            delete[] b;
    	}
    	return 0;
    }
```
# 3. 피드백

- 알고리즘 초반에 푼거라 동적 메모리 할당해서  입력받은 T 만큼의 사이즈를 가지는 배열을 생성했었는데 굳이 안이래도 될듯