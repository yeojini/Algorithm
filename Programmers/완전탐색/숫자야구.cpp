#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    bool flag=true;
    int strike;
    int ball;
    
    for(int i=123;i<=987;i++){ //가능한 최소 : 123, 최대 : 987
    
        string num = to_string(i);
        if(num[0]==num[1]||num[1]==num[2]||num[0]==num[2]) continue;
        
        else if (num[0]=='0' || num[1]=='0'||num[2]=='0') continue;
        
            flag = true;
            for(int j=0;j<baseball.size();j++){
                string num2 = to_string(baseball[j][0]);
                strike = 0;
                ball = 0;
                for(int a = 0;a<3;a++){
                    for(int b=0;b<3;b++){
                        if(a==b && num[a]==num2[b]){
                            strike++;
                        }
                        if (a!=b && num[a]==num2[b]){
                            ball++;
                        }
                    }
                }
                if(strike!=baseball[j][1] || ball!=baseball[j][2] ){
                   flag = false;
                    break;
                }
                
            }
        if(flag){
        answer++;
        }
    } 
    
    return answer;
}