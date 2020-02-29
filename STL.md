# 1.Vector

- 개체들을 연속적인 메모리 공간에 저장
- 즉, iterator 뿐 아니라 position index(operator [])로도 접근이 가능
- vector는 동적으로 확장/축소가 가능한 dynamic array로 구현되어 있다.
- **강점**
    - 원소를 컨테이너의 **끝**에 삽입/제거 하는 것이 빠르다
    - 어떠한 순서로도 원소들을 순회할 수 있다. 즉, Random access iterating이 가능함.
    - 다른 두 개의 시퀀스 컨테이너인 deque, list에 비해 **개별 원소에 대한 접근 속도와 컨테이너의 끝에서 삽입/제거하는 속도가 가장 빠르다**.
- **약점** : 중간에 값을 삽입 시 비효율적
- **주의**
    - **동적으로 컨테이너의 크기가 확장/축소**되는 것이 편하기는 하나, 확장시의 reallocation은 비용이 꽤 크다.
    - capacity를 확장 시켜줄 수 있는 적절한 크기의 reserve로 인한 메모리 확보가 중요.
```
    #include <iostream>	
    #include <vector>
    using namespace std;
    	int main(){
    	//int 자료형을 저장하는 동적배열
    	vector<int> vec1;
    	
    	//사용자가 정의한 Node 구조체를 저장하는 동적배열
    	vector<Node> vec3;
    	
    	//벡터의 초기 크기를 n으로 설정
    	vector<int> vec4(n);
    
    	//벡터의 초기 크기를 n으로 설정하고 1로 초기화
    	vector<int> vec5(n, 1);
    	
    	//크기가 n*m인 2차원 벡터를 선언하고 0으로 초기화
    	vector<vector<int> > vec6(n, vector<int>(m, 0));
    	
    	//벡터의 맨 뒤에 원소(5) 추가
    	vec1.push_back(5);
    
    	//벡터의 맨 뒤 원소 삭제
    	vec1.pop_back();
    
    	//벡터의 크기 출력
    	printf("%d\n", vec1.size());
    
    	//벡터의 크기를 n으로 재설정
    	vec1.resize(n);
    
    	//벡터의 모든 원소 삭제
    	vec1.clear();
    	
    	//벡터의 첫 원소의 **주소**, 마지막 원소의 다음 **주소** 리턴
    	vec1.begin();
    	vec1.end();
    	//vec1.front() : 벡터의 처음 **값**을 리턴
    	//vec1.back() : 벡터의 마지막 **값**을 리턴
    
    	//[a, b) 주소 구간에 해당하는 원소 삭제
    	vec1.erase(vec1.begin(), vec1.end());//모든 원소 삭제
    
    	//vec7은 vec1의 2번째 원소부터 마지막 원소까지 복사하여 생성
    	vector<int> vec7=vector<int>(vec1.begin()+2, vec1.end());
    
    	//vect8은 v7을 복사해서 생성
    	vector<int> v8(v7);
    
    		return 0;
    
    	}
```
# 2.Queue

- FIFO(first in first out) : 처음 들어온게 먼저나간다
```
    #include <iostream>
    
    #include <queue>
    
    using namespace std;
    
    int main(){
    
    //int자료형을 저장하는 큐 생성
    
    queue<int> q;
    
    //원소(4) 삽입
    
    q.push(4);
    
    //맨 위 원소 팝
    
    q.pop();
    
    //맨 위 원소 값 출력
    
    printf("%d\n", q.front());
    
    //큐가 비어있다면 1 아니면 0
    
    printf("%d\n", q.empty());
    
    //큐에 저장되어 있는 원소의 수 출력
    
    printf("%d\n", q.size());
    
    return 0;
    
    }
```
# 3.**Deque (double ended queue)**

- **강점**
    - 개별 원소들을 position index로 접근이 가능하다.
    - 원소를 컨테이너의 끝 뿐 아니라, 앞에서도 삽입(push_front)/제거(pop_front) 하는 것이 빠르다.
    - 어떠한 순서로도 원소들을 순회할 수 있다.
- **약점**
    - 컨테이너의 시작 / 끝 위치가 아닌 곳에서 삽입/제거 수행시 그 성능은 list에 비해 현저히 떨어진다.
- **장점**
    - 저장 원소가 많고 메모리 할당량이 큰 경우 vector에 비해 확장 비용이 절감된다.
- **단점**
    - 컨테이너 처음부터 끝까지 연속 메모리 공간이 아니므로, vector에서 가능했던 원소들간 포인터 연산이 불가능
```
        #include <iostream>	
        		#include <deque>
        		using namespace std;
        		int main(){
        		//int 자료형을 저장하는 동적배열 생성
        		deque<int> dq;
        		//배열 맨 앞에 원소(5) 추가
        		dq.push_front(5);
        		//배열 맨 뒤에 원소(5) 추가
        		dq.push_back(5);
        		//배열 맨 앞의 원소 삭제
        		dq.pop_front();
        		//배열 맨 뒤의 원소 삭제
        		dq.pop_back();
        		//나머지는 vector와 동일하다.
        		return 0;
        		}
```
# 4.Stack

- LIFO (last in first out) : 마지막으로 들어온게 먼저 나간다

        *s.size()
        
        -스택 사이즈
        
        *s.empty()
        
        -스택이 비어 있는지 아닌지
        
        c로 치면 isempty()같은거!
        
        *s.top()
        
        -스택 상단값​
        
        *s.push(data)
        
        -data값을 푸쉬
        
        *s.pop()
        
        -스택 top을 팝
        

# 5.list

- **강점**
    - 컨테이너의 어느 위치에서도 삽입/제거가 빠르다 (상수 복잡도)
    - 원소들의 컨테이너 내 순서 이동이 빠르다. (상수 복잡도)
    - vector와 deque와 다르게 list의 가장 큰 강점은 **컨테이너 내 어느 위치에서도 원소의 삽입/제거가 빠르다**는 것이다.
- **약점**
    - 원소의 **position index로 직접 접근이 불가능**하다.
    : 특정 원소에 접근하려면 처음이나 끝에서부터 **선형 탐색**을 하여야만 한다.
    - 컨테이너 내 원소 순회는 forward / reverse 순회만 가능하며, 느리다. (선형 복잡도)
    - 원소들간 상호 연결 정보를 위해 추가적인 메모리가 사용된다.
```
    #include <iostream>
    #include <list>//list 헤더파일
    
    int main(){
        std::list<int> l;//기본 선언
        std::list<int> l(10);//원소 10개를 가진 list 선언 
        std::list<int> l(10,2);//2로 초기화된 변수 10개
        std::list<int> l2(l); //복사
    		l.front();//list 의 맨 앞 원소
    		l.back(0; //list 의 맨 뒤 원소
    		
    		l.begin(); //맨 앞 주소값 for 문에서 iterator와 함께 사용
    		l.end(); //맨 뒤 주소값
    
    		std::list<int>::iterator iter;//요런식으로 선언후
    		for(iter=l.begin(); iter!=l.end(); iter++){
            std::cout<<*iter<<std::endl;
    		}//요런식으로 사용
    
    		l.rbegin(); //reverse begin. end 부터 시작
    		l.rend(); //reverse end. begin 부터 시작
    
    		std::list<int>::reverse_iterator riter;
    		//이때는 반드시 reverse_iterator를 사용해야된다
    
    		for(riter=l.rbegin();riter!=l.rend();riter++){
            std::cout<<*riter<<std::endl;
        }//요런식으로 사용하면 된다.
    
    		l.insert(iter,data); //현재 iter 가 가르키는 곳에 data 삽입
    		
    		//list에 1,2,3,4,5가 저장되어 있다고 가정
    
    		for(iter=l.begin(); iter!=l.end(); iter++){
            l.insert(iter,7);
        }
    
    		출력: 7 1 7 2 7 3 7 4 7 5
    	//해당하는 iter앞에 7이 저장된다.
    
    		l.erase(iter); // iter 가 가르키는 변수를삭제한다.
    
    		//list에 1,2,3,4,5가 저장
    
    		for(iter=l.begin(); iter!=l.end(); iter++){
            if(*iter==4){
                l.erase(iter);
            }
        }
    
    		출력:1 2 3 5
    
    		l.remove(data); //리스트 내의 data 와 같은 변수 모두 삭제
    		
    		l.remove_if(bool type function); //true 인 값 제거
    
    		l.reverse(); //list 를 뒤집는다.
    
    		l.sort(); //오름차순 정렬
    		
    		bool func(int a,int b){
    	    return a>b;
    		}
    
    		l.sort(func); //내림차순 정렬
    
    		l.unique(); //양 옆에 같은 원소가 있으면 하나빼고 다 제거
    		//sort 후 사용하면 중복제거 할 수 있을듯
    
    		l.merge(l2); // l 에 l2 를 합쳐 오름차순 정렬
    
    		l2.splice(iter,l); //iter 가 가르키는 곳에 l의 모든원소 자르고 l2에 붙이기
    		l2.splice(iter,l,iter_1); //l2 에 iter 가가르키는곳에 l의 iter_1 이 가르키는 원소 자르고 붙이기
    		l2.splice(iter, l , iter1_1, iter1_2); //l2에 iter 가가르키는 곳의 l의 iter1_1~iter1_2 까지자르고 붙이기
    		
    
    
    		
    
    		 
        return 0;
    }
```    

# 6.Set

- 일반 vector,list,deque 와는 다르게 key 값도 같이저장
- 중복된 데이터 허용 X
- 중복된 데이터 → multiset
- 이진트리로 구성 → 자동 정렬
```
    #include <iostream>
    #include <set>
    using namespace std;
    		int main(){
    		//int 자료형을 저장하는 균형잡힌 이진트리 생성
    		set<int> s;
    		//원소(5) 삽입
    		s.insert(5);
    		//6값을 가지는 원소를 찾음 있다면 해당 원소의 주소값, 없다면 s.end()리턴
    		if(s.find(6)!=s.end())
    		printf("존재합니다.\n");
    		else
    		printf("없습니다.\n");
    		//저장된 원소의 수를 리턴
    		printf("%d\n", s.size());
    		//모든 원소 삭제
    		s.clear();
    		//해당 주소의 원소 삭제
    		//2번째 원소 삭제
    		s.erase(++s.begin());
    		return 0;
    		}
```
# 7. Pair
```
    #include <iostream>	
    		#include <utility>
    		using namespace std;
    		int main(){
    		//int, int 자료형을 저장하는 변수 선언
    		pair<int, int> p;
    		//(4, 5)를 p에 저장
    		p=make_pair(4, 5);
    		//c++11부터 가능
    		p={4, 5};
    		
    		cin >> p1.first >> p1.second ; 
    
    		//정렬 - pair 객체가 5사이즈의 vector<pair<int,int>> 에 저장되어 있다고 가정
    		sort(v.begin().v.end()); 
    		//first 원소를 기준으로 정렬 후 second 원소를 기준으로 정렬
    		return 0;
    
    		}
```
# 8. Map
```
    #include <iostream>	
    		#include <map>
    		using namespace std;
    		int main(){
    		//int 자료형을 key로 int 자료형을 데이터로 저장하는 딕셔너리 자료구조 생성
    		map<int, int> m;
    		//(4, 5)원소 삽입
    		m.insert(make_pair(4, 5));
    		//또는
    		m[5]=6;
    		//key와 연관된 원소를 pair<키 자료형, 데이터 자료형> 형태로 리턴함
    		printf("%d\n", m.find(4)->second);
    		//key와 연관된 원소의 개수를 리턴함
    		printf("%d\n", m.count(4));
    		//저장된 원소의 수를 리턴함
    		printf("%d\n", m.size());
    		//해당 주소의 원소 삭제
    		m.erase(++m.begin());
    		//모든 원소 삭제
    		m.clear();
    		return 0;
    		}
```
# 9. Algorithm
```
    #include <iostream>	
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    bool cmp(const int a, const int b){
    		return a>b;
    }
    
    int main(){
    		
    		int arr1[100000];
    		vector<int> arr2[100000];
    		int n=100000;
    		
    		//sort
    		//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
    		sort(arr1, arr1+n);
    		sort(arr2.begin(), arr2.end());
    		//비교 함수도 만들어서 같이 넘겨줄 수 있다.
    		sort(arr1, arr1+n, cmp);
    		
    		//stable_sort
    		//사용법은 같다.
    		stable_sort(arr1, arr1+n);
    		
    		//lower_bound
    		//첫 원소의 주소와 마지막 원소의 다음 주소와 비교할 원소를 넘겨준다.
    		//구간내의 원소들은 정렬되어 있어야한다.
    		//리턴 값은 해당 원소의 주소값이다. 없다면 arr1+n을 리턴한다.
    		//또는 arr2.end()를 리턴한다.
    		int idx=lower_bound(arr1, arr1+n, 42)-arr1;
    		printf("%d\n", idx);
    		
    		//upper_bound
    		//사용법은 같다.
    		vector<int>::iterator it=upper_bound(arr2.begin(), arr2.end(), 54);
    		if(it!=arr2.end())
    		printf("%d\n", *it);
    		
    		//max_element
    		//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
    		//구간내의 최대값을 가지는 원소의 주소를 리턴한다.
    		printf("%d\n", *max_element(arr1, arr1+n));
    		
    		//min_element
    		//사용법은 같다.
    		printf("%d\n", *min_element(arr2.begin(), arr2.end()));
    		
    		//unique
    		//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
    		//구간내의 중복된 원소를 구간의 끝부분으로 밀어주고 마지막 원소의 다음 주소를 리턴한다.
    		//구간내의 원소들은 정렬되어 있어야한다.
    		//보통 erase와 함께 중복된 원소를 제거하는 방법으로 사용한다.
    		arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
    		
    		//next_permutation
    		//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
    		//구간내의 원소들의 다음 순열을 생성하고 true를 리턴한다.
    		//다음 순열이 없다면 false를 리턴한다.
    		//구간내의 원소들은 정렬되어 있어야한다.
    		int arr[10];
    		for(int i=0;i<10;i++)
    		arr[i]=i;
    		do{
    		for(int i=0;i<10;i++)
    		printf("%d ", arr[i]);
    		printf("\n");
    		}while(next_permutaion(arr, arr+10));
    		
    		return 0;
    	}
```