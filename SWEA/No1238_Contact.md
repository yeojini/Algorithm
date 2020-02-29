# 1. Ǯ��

- ������ �Ѿ�� �ֱ� �� queue ���.
- 100���� ����� 100���� ������� �����Ҽ� �����Ƿ� �������迭 call[101][101] ����
- from, to �Է¹����� call[from][to] �� 1�� �ȴ�
- �湮�ߴ��� ���ߴ��� check �ϴ� visited[101] ����. visited[i]==true �� �湮�ؾ��� ť�� �������� �ʴ´�.
- ���� ������ �ֱ⿡ �����޴� ������� �����ϴ� queue ����. ����å queue �� ��� while ���� Ż���ϰ� �Ǿ� �������� �Ѿ��. while �� �� ����Ŭ�� �������� �ʹݿ�  �����޴� queue �� �ʱ�ȭ������Ѵ�.

# 2. �ڵ�
```
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <string.h>
    using namespace std;
    
    int call[101][101];
    bool visited[101] = {false,};
    
    int res;
    queue<int> f;
    queue<int> t; //�������� �����޴� �ֵ�
    
    int solve(int n) {
    	int max = 0;
    	visited[n] = true;
    	f.push(n);
    	while (!f.empty()) {
    		int f_size = f.size(); // �� ����Ŭ�� ������ ����� ��
    		while (!t.empty()) t.pop(); //������� clear
    
    		//�� ����å�� ���� ��������� ����å queue �� push
    		for (int i = 0; i < f_size; i++) {
    
    			int f_front = f.front(); //����å�� ������ �����ϰ�
    			f.pop(); //ť���� ����
    			t.push(f_front); //���ÿ� �������� �ֵ� 
    			
    			for (int j = 0; j < 101; j++) {
    				if (call[f_front][j] == 1 && !visited[j]) { //���������ϰ� �������� ������
    					visited[j] = true; //�湮�ߴٰ� �ϰ�
    					f.push(j);//������ ����� �߰�
    				}
    			}
    		} //�ѻ���Ŭ ��
    	}//���������� ����� ������ queue f �� ��� �Ǿ� while �� Ż��
    		
    
    	while (!t.empty()) {
    		int t_front = t.front();
    		t.pop();
    		if (t_front > max) max = t_front;
    	}
    	
    	return max;
    }
    
    int main() {
    	int length;
    	int start;
    	for (int tc = 1; tc <11; tc++) {
    
    		memset(call, 0, sizeof(call));
    		memset(visited, 0, sizeof(visited));
    
    		cin >> length >> start;
    		
    		for (int i = 0; i < length/2; i++) {
    			int from;
    			int to;
    			cin >> from>>to;
    			call[from][to] = 1;
    		}
    
    		cout << '#' << tc << ' '<<solve(start) << '\n';
    	}
    	return 0;
    }
```
# 3. �ǵ��