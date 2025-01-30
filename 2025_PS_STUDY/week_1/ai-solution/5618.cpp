#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 최대공약수 계산 - 유클리드 호제법
int getGcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 약수 구하기 최적화 함수
void findDivisors(int n) {
    vector<int> divisors;
    // sqrt(n)까지만 순회
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            // i*i != n 조건으로 중복 방지
            if(i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    // 오름차순 정렬
    sort(divisors.begin(), divisors.end());
    // 출력
    for(int div : divisors) {
        cout << div << '\n';
    }
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    // 첫 번째 수 입력
    int a;
    cin >> a;
    
    // GCD 계산
    if(n >= 2) {
        int b;
        cin >> b;
        a = getGcd(a, b);
    }
    
    // 세 번째 수가 있으면 처리
    if(n == 3) {
        int c;
        cin >> c;
        a = getGcd(a, c);
    }
    
    // 모든 공약수 출력
    findDivisors(a);
    
    return 0;
}

/* GitHub Copilot
최적화 포인트
1. 메모리 사용 개선

불필요한 전역 배열 제거
vector 동적 할당 사용

2. 성능 최적화

유클리드 호제법 반복문 버전 사용
약수 찾기 O(√n) 복잡도 구현

시간복잡도
GCD 계산: O(log n)
약수 찾기: O(√n)
정렬: O(k log k), k는 약수의 개수

추천 질문
큰 수의 GCD를 구할 때 성능 개선 방법은?
약수 찾기의 다른 알고리즘은?
병렬처리로 최적화할 수 있는 부분은?
*/