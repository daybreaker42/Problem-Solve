#include <bits/stdc++.h>
// #include <asdf.jh>

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const bool debug = false;

map<char, int> charMap = {
    {'-', 0},
    {'\\', 1},
    {'(', 2},
    {'@', 3},
    {'?', 4},
    {'>', 5},
    {'&', 6},
    {'%', 7},
    {'/', -1}
};

int parseValue(string targetValue);
int eightPower(int p);

int main() {
	fastio;

    string inputVal;

    while(true){
        getline(cin, inputVal);
        if(inputVal == "#") break;
        int parsedVal = parseValue(inputVal);
        cout << parsedVal << "\n";
    }
    

	return 0;
}

int parseValue(string targetValue){
    int length = targetValue.size();
    int result = 0;

    for(int i = 0; i < length; i++){
        int value = eightPower(length - 1 - i) * charMap[targetValue[i]];
        result += value;
        // cout << value << " ";
    }
    // cout << "----------\n";
    return result;
}

int eightPower(int p){
    int result = 1;
    for(int i = 0; i < p; i++){
        result *= 8;
    }
    return result;
}


/* 250124 배운 점
## 핵심 아이디어
- map에 각 숫자를 맵핑시킨 후, 대응하는 문자를 숫자로 변환시키기.
- 이후 8진수를 10진수로 변환하기 위해 8^(각 자리수)를 한 결과들을 다 더해줌.

## 어려웠던 점
- map 자체를 오랜만에 써봐서 어려웠음. 어떻게 선언하는지, 각 요소들은 어떻게 초기화하는지 완전히 까먹었었음.
    -> map의 각 요소들도 중괄호로 묶어줘야 함.
- g++ 컴파일러 설정이 어려웠음. 그리고 아직 완전히 설정이 끝난게 아닌지 컴파일러는 정상으로 돌아가는데 lint에서 오류 표시를 자꾸 함.
*/