#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool isPrime(int n) {
    // 1은 소수가 아님
    if(n == 1) return false;
    
    // 2부터 sqrt(n)까지 나누어 떨어지는지 확인
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(isPrime(num)) count++;
    }
    
    cout << count;
    
    return 0;
}

/* ai comment
코드 설명
최적화 포인트

sqrt(n)까지만 검사하여 시간 복잡도 개선
불필요한 배열 사용 제거
fastio 사용으로 입출력 속도 개선
시간 복잡도

각 수마다 O(√N) 검사
전체 시간복잡도: O(N√M), N은 입력 수의 개수, M은 입력값 중 최댓값
추천 추가 질문
1. 에라토스테네스의 체를 활용하면 어떻게 성능이 개선될까요?
2. 병렬 처리를 통해 소수 판별을 최적화할 수 있을까요?
3. 메모이제이션을 활용하면 어떤 이점이 있을까요?
질문 평가
master의 코드는 기본적인 구현이 잘 되어 있습니다. 다만 개선할 수 있는 부분:

- 문제의 제약조건 명시
- 예제 입출력 케이스 포함
- 최적화 방법에 대한 고려사항 설명

Microsoft Docs와 C++ 표준 문서에 따르면, 이러한 수학적 계산에서는 <cmath> 헤더의 sqrt() 함수를 사용하는 것도 고려해볼 만합니다.

*/