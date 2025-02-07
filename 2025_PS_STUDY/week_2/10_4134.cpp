#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ui unsigned int
using namespace std;

// const bool debug = false;

bool isPrime(ui n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t-- > 0){
        ui n;
        cin >> n;
        while(!isPrime(n)){
            n++;
        }
        cout << n << "\n";
    }

	return 0;
}


// ai 최적화 코드
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ui unsigned int
using namespace std;

// 소수 판별 함수
bool isPrime(ui n){
    if(n <= 1) return false;  // 1이하는 소수가 아님
    if(n == 2) return true;   // 2는 소수
    if(n % 2 == 0) return false;  // 2외의 짝수는 소수가 아님
    
    // 홀수만 체크 (최적화)
    for(ui i = 3; i * i <= n; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    fastio;
    
    int t;
    cin >> t;
    while(t-- > 0){
        ui n;
        cin >> n;
        while(!isPrime(n)){
            n++;
        }
        cout << n << "\n";
    }
    
    return 0;
}
 */