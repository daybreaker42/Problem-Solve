#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 다음 수를 생성하는 함수
int getNextNumber(int num) {
    int units = num % 10;           // 일의 자리
    int tens = num / 10;           // 십의 자리
    int sum = units + tens;        // 각 자리 합
    return (units * 10) + (sum % 10); // 새로운 수 생성
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    // 입력값 범위 검증 (0 ≤ N ≤ 99)
    if(n < 0 || n > 99) return 1;
    
    int current = n;
    int cycle = 0;
    
    // 사이클 찾기
    do {
        current = getNextNumber(current);
        cycle++;
    } while(current != n);
    
    cout << cycle;
    
    return 0;
}

/** 
 * 개선사항 설명
코드 가독성

함수 모듈화로 로직 명확화
변수명을 의미있게 변경
Microsoft C++ 스타일 가이드 준수
안정성

입력값 범위 검증 추가
do-while 문으로 로직 단순화
성능

O(N) 시간복잡도 유지
불필요한 조건문 제거
추천 추가 질문
수열의 주기성을 이용한 최적화는 가능할까요?
비트 연산으로 성능을 개선할 수 있을까요?
메모이제이션으로 반복되는 패턴을 저장할 수 있을까요?
문제 평가
master의 코드는 기본적인 구현은 잘 되어있으나, 다음과 같은 점들이 개선되면 좋을 것 같습니다:

입력값 범위에 대한 검증 추가
변수명을 더 직관적으로 변경
주석을 통한 코드 설명 보강
 */