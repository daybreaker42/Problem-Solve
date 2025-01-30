#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const bool debug = false;

bool isPrime(int n);

int main() {
	fastio;
    int m, n;
    cin >> m >> n;
    // solving
    int sumPrime = 0, minPrime = 10000;
    for(int i = m; i <= n; i++){
        if(isPrime(i)){
            sumPrime += i;
            minPrime = min(minPrime, i);
        }
    }

    if(minPrime == 10000){
        cout << -1;
    }else{
        cout << sumPrime << "\n" << minPrime;
    }

	return 0;
}

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

/* 배운 점
주의 : 1은 소수가 아니다
 */