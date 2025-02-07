#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// const bool debug = false;
int arr[SIZE] = {0};

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    short t;
    cin >> t;
    while(t-- > 0){
        short n;
        cin >> n;
        long long sum = 0;
        for(short i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(short i = 0; i < n; i++){
            for(short j = i + 1; j < n; j++){
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << "\n";
    }

	return 0;
}

// comment
/*
- sum 조합의 크기 * 10^6 만큼 커질 수 있으므로 overflow에 유의해 long long으로 선언할 것.
*/

// ai solution
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

vector<int> arr;  // 동적 배열 사용

// 최적화된 GCD 함수
int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    fastio;
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        arr.resize(n);  // 벡터 크기 조정
        
        // 입력
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // GCD 합 계산
        long long sum = 0;  // 오버플로우 방지
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                sum += gcd(arr[i], arr[j]);
            }
        }
        
        cout << sum << "\n";
    }
    
    return 0;
}
*/

/*
주요 변경사항 설명
벡터 사용

정적 배열 대신 동적 배열 사용
메모리 효율성 향상
GCD 최적화

비재귀적 구현으로 변경
스택 오버플로우 방지
실행 속도 향상
자료형 최적화

short 대신 int 사용 (최신 CPU에서 더 효율적)
sum을 long long으로 유지
성능 분석
시간복잡도: O(T * N^2 * log(max(arr[i])))
공간복잡도: O(N)
추천 추가 질문/키워드
GCD의 시간복잡도와 최적화 방법
벡터와 정적 배열의 성능 차이
정수 오버플로우 방지 전략
질문 평가
master의 질문은 명확하나, 다음 사항이 추가되면 좋았을 것 같습니다:

입력값의 범위
시간/메모리 제한
특수 케이스 처리 요구사항
*/