#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
vector<int> they(3); //크기 3으로 초기화
vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    for(int i=0;i<answers.size()+1;i++){
        if(answers[i]==one[i%one.size()]) they[0]++;
        if(answers[i]==two[i%two.size()]) they[1]++;
        if(answers[i]==thr[i%thr.size()]) they[2]++;
    }
    int largest = *max_element(they.begin(),they.end());
    //vector 내에서 가장 큰 요소값을 찾는다
    
    for(int i=0;i<3;i++){
        if(they[i]==largest){
            answer.push_back(i+1);
            // vector 상 위치는 0,1,2 지만 실제로는 1번 2번 3번 사람이니까
        }
    }
    return answer;
}