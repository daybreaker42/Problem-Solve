#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500000
using namespace std;

// const bool debug = false;

int arr[SIZE] = {0};

int gcd(int n, int m){
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;

    // solving
    int cnt = 0;
    double ave = 0;
    for(int i = 0; i < n; i++){
        if(gcd(arr[i], x) == 1){
            cnt++;
            ave += arr[i];
        }
    }

    ave /= cnt;
    cout << fixed;
    cout.precision(7);
    cout << ave;

	return 0;
}


/* 서로소 평균 comment
- 서로소 판정 기준 ==> 두 수의 GCD가 1일때
*/

// ai solution

/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500000
using namespace std;

vector<int> arr;  // 동적 배열로 변경

// 최대공약수 계산 함수 (유클리드 호제법)
int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main() {
    fastio;
    
    int n, x;
    cin >> n;
    
    // 수열 입력
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> x;
    
    // 서로소인 수들의 합과 개수 계산
    long long sum = 0;  // 오버플로우 방지
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        if(gcd(arr[i], x) == 1){
            sum += arr[i];
            cnt++;
        }
    }
    
    // 평균 계산 및 출력
    double ave = (double)sum / cnt;
    cout << fixed;
    cout.precision(6);  // 문제 요구사항에 맞춤
    cout << ave;
    
    return 0;
}
*/

/*
주요 최적화 포인트
벡터 사용

정적 배열 대신 동적 배열 사용
메모리 효율성 개선
오버플로우 방지

sum 변수를 long long으로 선언
큰 수의 합 계산 시 정확성 보장
GCD 함수 최적화

더 간단한 형태의 유클리드 호제법 사용
불필요한 swap 연산 제거
성능 분석
시간복잡도: O(N * log(max(arr[i])))
공간복잡도: O(N)
추천 추가 질문/키워드
서로소의 개념과 응용 분야는?
부동소수점 정밀도와 오차 처리는?
메모리 동적 할당의 장단점은?
질문 평가
master의 질문은 명확하나, 다음 사항이 추가되면 좋았을 것 같습니다:

입력값의 범위
출력 형식의 정확한 요구사항
시간/메모리 제한 조건
*/