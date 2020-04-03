#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int width=0;
    int height=0;
    int s = brown + red;
    for(int width=1;width<s;width++){
        height = s/width;
        if(width * height == s && width >= height&&(red == (width-2)*(height-2))){
            answer.push_back(width);
            answer.push_back(height);
        }
    }
    
    return answer;
}