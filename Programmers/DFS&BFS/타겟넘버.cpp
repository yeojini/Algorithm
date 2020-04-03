#include <string>
#include <vector>

using namespace std;

int T;
int N;
int ans;

void DFS(int cnt, int result, vector<int> numbers){
    if(cnt == N){
        if(result == T) ans++;
        return;
    }
    DFS(cnt+1,result + numbers[cnt],numbers);
    DFS(cnt+1,result - numbers[cnt],numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    T = target;
    N = numbers.size();
    DFS(0,0,numbers);
    answer = ans;
    
    return answer;
}