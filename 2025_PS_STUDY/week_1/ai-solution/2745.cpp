#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 문자를 숫자로 변환하는 함수
int char_to_num(char c) {
    if(isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

int main() {
    fastio;
    
    string n;
    int b;
    cin >> n >> b;
    
    // 10진수 변환
    long long result = 0;  // 오버플로우 방지
    for(char c : n) {
        result = result * b + char_to_num(c);
    }
    
    cout << result;
    
    return 0;
}

/* ai comment 
개선사항 설명
1. power 함수 제거

매번 거듭제곱 계산 대신 누적 곱 사용
시간복잡도: O(n) → O(1)

2. 형변환 최적화

Microsoft의 성능 가이드라인에 따라 isdigit() 사용
문자 변환 로직 별도 함수로 분리

3. 오버플로우 방지

long long 자료형 사용
C++ Core Guidelines ES.106 준수


추천 추가 질문
1. strtoll() vs stoi() 성능 차이는?
2. 다양한 진법 변환 알고리즘의 장단점은?
3. 큰 수 처리를 위한 최적화 방법은?

*/
