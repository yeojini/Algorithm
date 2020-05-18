# 문제

# 풀이

'A'- 32 = 0 = 'a' - '97 = '0' - 48 이용해
공백이 아닌 문자가 대문자 이면 'A' +32 = 'a' 로 변환한다 

# 코드
```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string str,str2;
	getline(cin,str);
	
	for(int i=0;i<str.size();i++){
		if(str[i]!=' '){
			if('A'<=str[i] && str[i]<='Z'){
				str[i]=str[i]+32;
			}
			
			str2+=str[i];
		}
	}
	cout << endl;
	cout << str2;
	
}
```