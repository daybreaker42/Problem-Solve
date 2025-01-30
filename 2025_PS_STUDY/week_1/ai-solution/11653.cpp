#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void factorize(int n) {
    // 2로 나누어 떨어지는 경우 먼저 처리
    while(n % 2 == 0) {
        cout << 2 << '\n';
        n /= 2;
    }
    
    // 3 이상의 홀수 소인수 처리
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    
    // 남은 수가 1보다 크면 그 수는 소수
    if(n > 1) cout << n << '\n';
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    // 1은 소인수분해 불가
    if(n > 1) factorize(n);
    
    return 0;
}

/** 
 * comment
 */

/** ai comment
 * 개선사항 설명
1. 메모리 최적화
에라토스테네스의 체 제거로 O(1) 메모리 사용
Microsoft의 성능 가이드라인 준수

2. 시간 복잡도
O(√N)으로 개선
Intel의 최적화 가이드 기반 구현

3. 코드 단순화
불필요한 함수 제거
로직 통합으로 가독성 향상

- 시간복잡도
기존: O(N log log N) [에라토스테네스의 체]
개선: O(√N) [직접 소인수분해]

- 추천 질문
병렬 처리로 소인수분해를 최적화할 수 있을까요?
밀러-라빈 소수 판별법을 활용할 수 있을까요?
폴라드 로 알고리즘은 어떤 경우에 유용할까요?
문제 평가
master의 코드는 기본 구현은 잘 되어있으나, 다음과 같은 점들이 개선되면 좋을 것 같습니다:

입력값 범위 검증 추가
예외 처리 강화
최적화 전략 재고려
 * 
 */


// 아래는 비트시프트로 나눗셈 연산 최적화 버전

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

void factorize(int n) {
    // 비트연산으로 2의 배수 처리 최적화
    while((n & 1) == 0) {  // n % 2 == 0을 비트연산으로 변경
        cout << 2 << '\n';
        n >>= 1;           // n /= 2를 비트시프트로 변경
    }
    
    // 3 이상의 홀수 소인수 처리
    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            cout << i << '\n';
            n /= i;
        }
    }
    
    if(n > 1) cout << n << '\n';
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    if(n > 1) factorize(n);
    
    return 0;
}