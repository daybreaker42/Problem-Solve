#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define SIZE 10000
using namespace std;

// const bool debug = false;

int arr[SIZE] = {0};

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    ll ans = 1;

    for(int i = 0; i < n; i++){
        if(isPrime(arr[i]) && ans % arr[i] != 0){
            ans *= arr[i];
        }
    }

    if(ans == 1){
        ans = -1;
    }
    
    cout << ans;
    
	return 0;
}

// comment
/*
- N <= 10000이고, Ai <= 10^6 -> 제곱근 방식으로 소수 판정해도 10^8번 이하 계산 -> 제곱근 방식 가능할수도?

- 정답이 long long 범위임에 유의 (정수합, 곱 등이 나올 경우 -> int 범위인지 바로 확인)
- 소수끼리의 최소공배수는 그들의 곱이지만, 같은 소수가 나오는 경우 유의.
*/

// ai solution

/*

// 1 - 제곱근 판별 사용

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define SIZE 10000

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    // 중복 제거를 위한 set 사용
    set<int> uniqueNumbers;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        uniqueNumbers.insert(num);
    }
    
    // 소수들의 최소공배수 계산
    ll ans = 1;
    for(int num : uniqueNumbers){
        if(isPrime(num)){
            ans *= num;
        }
    }
    
    cout << (ans == 1 ? -1 : ans);
    
    return 0;
}

*/

/*

// sol 2)

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define MAX 1000001  // 문제 제한 조건에 따른 최대값

using namespace std;

vector<bool> isPrime(MAX, true);  // 소수 판별 배열

// 에라토스테네스의 체 초기화
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < MAX; i++) {
        if(isPrime[i]) {
            // i의 배수들을 모두 false로 표시
            for(int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    fastio;
    
    // 소수 판별 전처리
    sieve();
    
    int n;
    cin >> n;
    
    set<int> uniqueNumbers;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        uniqueNumbers.insert(num);
    }
    
    ll ans = 1;
    for(int num : uniqueNumbers) {
        if(isPrime[num]) {  // O(1) 시간복잡도로 소수 판별
            ans *= num;
        }
    }
    
    cout << (ans == 1 ? -1 : ans);
    
    return 0;
}
*/

/*
최적화 설명
시간복잡도 개선

기존: O(N * √M) → 개선: O(M log log M + N)
M은 최대값(10^6), N은 수열 길이
전처리는 한 번만 수행, 이후 O(1) 판별
성능 수치

기존 방식: 각 숫자당 최대 1000번의 나눗셈 연산
개선 방식: 전처리 후 배열 접근 1회로 판별 가능
추천 추가 질문
비트마스킹을 활용한 메모리 최적화 방법은?
병렬처리를 통한 에라토스테네스의 체 최적화는?
세그먼트 체(Segmented Sieve) 알고리즘의 활용은?
질문 평가
좋은 질문이지만, 구체적인 최적화 목표(시간/공간)와 제약조건을 명시했다면 더 좋았을 것 같습니다
*/