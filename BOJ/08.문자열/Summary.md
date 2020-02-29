# 1. 문자열→int, int→ 문자열

- int num = 12345; string s = to_string(num);
- string s = "12345"; int num = atoi(s.c_str());, stoi(s);

# 2. find

- s.find(string f, int start ) / s.find(char c,int start) : 문자열 s의 start 부터 f 혹은 c 가 있는지 검사한다.
    - return : 첫글자가 나온 index, 찾지못하면 -1
- s.find(string f, int start, int min) : 문자열 s 에서 start 부터 연속으로 최소 min 만큼 일치하는 것을 찾는다.

# 3. substr

- s.substr(int i) : 문자열 s 를 i번째부터끝까지자른다.
- s.substr(int i,int j) : 문자열 s 를 i번째부터 j만큼 자른다.

# 4. 아스키코드 응용

> 'A'-65 = 0 = 'a' - 97 = '0' - 48

# 5. 문자열 입력 받기

- getline
    - char :
```
            char arr[10]; // 문자열은 끝을 나타내기 위한 \0 이 저장될 공간까지고려해야함
            cin >> arr; //
            cin.getline(arr,10); // 문자열의 크기를 항상지정해주어야함
            //처음들어온 띄어쓰기, \n,tab 무시한다
            //9개 까지만 입력 가능
```

    - string : 문자열의 크기에 제약이 없다.
```
            string name;
            cin >> name; //띄어쓰기 까지만 입력받는다, 
            getline(cin,name);
```