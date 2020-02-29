# 재귀 함수

> 자신이수행할 작업을 유사한 형태의 여러 조각으로 쪼갠 뒤 그 중 한 조각을 수행하고, 나머지를 자기 자신을 호출해 실행하는 함수

    int recursiveSum(int n){
    	if(n==1) return 1;
    	return n+recursiveSum(n-1);
    }

- 모든 재귀 함수는 더이상 쪼개지지 않는 최소한의 작업에 도달했을 때 답을 바로 반환하는 조건문을 포함해야 한다.
- 이 때의 쪼개지지 않는 가장 작은 작업 : **기저 사례 (baseline)**
- 기저 사례 선택 시 모든 입력이 항상 기저 사례의 답을 이용해 계산 될 수 있도록 해야 함.

## [ex 1] 중첩 반복문 대체하기

- 문제 : n 개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘

    #include <iostream>
    #include <vector>
    using namespace std;
    
    //n:원소의 총 개수
    //picked : 지금 까지 고른 원소들의 번호
    //toPick : 더 골라야 할 원소들의 개수1
    
    void printPicked(vector<int>& picked) {
    
    	for (int i = 0; i < picked.size(); i++) {
    		cout << picked[i] << "  ";
    	}
    	cout << endl;
    	return;
    }
    
    void pick(int n, vector<int>& picked, int toPick) {
    	if (toPick == 0) { 
    		printPicked(picked);
    		return;
    	}
    
    	//picked 의 사이즈가 0 이라면 smallest 는 0, 아니라면 마지막 원소번호+1/
    	int smallest = picked.empty() ? 0 : picked.back() + 1;
    
    	for (int next = smallest; next < n; ++next) {
    		picked.push_back(next);
    		// 맨뒤에 원소 next 추가
    		
    		pick(n, picked, toPick - 1);
    		
    		picked.pop_back();
    		//맨 뒤의 원소 삭제
    	}
    }
    
    
    int main() {
    
    	int n, m;
    	cin >> n;
    	cin >> m;
    
    	vector<int> v;
    	pick(n, v, m);
    
    	return 0;
    }
