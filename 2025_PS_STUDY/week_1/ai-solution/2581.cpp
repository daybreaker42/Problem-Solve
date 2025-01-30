#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool isPrime(int n) {
    // 1은 소수가 아님
    if(n == 1) return false;
    
    // 2부터 제곱근까지만 확인
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    fastio;
    
    int m, n;
    cin >> m >> n;
    
    int sum = 0;
    int min_prime = -1;
    
    // m부터 n까지 소수 찾기
    for(int i = m; i <= n; i++) {
        if(isPrime(i)) {
            if(min_prime == -1) min_prime = i;
            sum += i;
        }
    }
    
    // 결과 출력
    if(min_prime == -1) {
        cout << -1;
    } else {
        cout << sum << '\n' << min_prime;
    }
    
    return 0;
}