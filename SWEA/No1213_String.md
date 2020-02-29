# 1. 풀이

1. 입력받은 문자열 s 를 입력받은 문자열 S 내에 몇개 있는지 출력하는 코드
2. S.find(S 내에서 찾을 문자열(s),찾기 시작할 인덱스) 
    - 찾으면 찾은 곳의 idx 반환
    - 못찾으면-1 반환
3. 못찾을 때까지 , 찾았을때 result++, 찾기 시작할 인덱스를 (찾은 인덱스+찾을 문자열의 사이즈 )로 지정

# 2. 코드
```
    #include<iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	string S, s;
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
        int tc;
		cin >> tc;
		cin >> s;
		cin >> S;
		int result = 0;
		int nidx = 0;
		//있다면

		while (S.find(s, nidx) != -1) {
			nidx = S.find(s, nidx) + s.size();
			result++;
		}
		
		cout << "#" << test_case << " " << result<<"\n";

	}

	return 0;
}
```

# 3. 피드백