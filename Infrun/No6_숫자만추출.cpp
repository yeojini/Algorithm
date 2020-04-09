/*
문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만 
듭니다. 만들어진 자연수와 그 자연수의 약수 개수를 출력합니다.
만약 “t0e0a1c2her”에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수를 만들면 12가 됩니 
다. 즉 첫 자리 0은 자연수화 할 때 무시합니다.  출력은 12를 출력하고, 다음 줄에 12의 약 
수의 개수를 출력하면 됩니다.
추출하여 만들어지는 자연수는 100,000,000을 넘지 않습니다.
- 입력설명
첫 줄에 숫자가 썩인 문자열이 주어집니다. 문자열의 길이는 50을 넘지 않습니다.
- 출력설명
첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다.
*/


#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string str,tmp;
	int mul=1;
	int cnt=0;
	int sum=0;
	bool flag = false;
	cin >> str;
	for(int i=0;i<str.size();i++){
		if(str[i]-48>0&&!flag) flag = true;
		if(str[i]-48>=0 && str[i]-48<10){
			if(flag){
				tmp += str[i];	
			}
			
		}
		
		//강의를 듣고.. 매우 간단한게 있었다..
		//sum = sum*10+str[i]-48; (0 이오면 계속 sum 은 0 이 되고 아닌게 와야 일의 자리수에 추가되고 그 전 값들은 왼쪽으로 자리수 )
		
	}
	for(int i=tmp.size()-1;i>=0;i--){
			sum += (tmp[i]-48)*mul;
			mul*=10;
	}
	cout << sum << "\n";
	
	for(int i=1;i<=sum;i++){
		if(sum%i==0){
			cnt++;
		}
	}
	cout << cnt;
}
