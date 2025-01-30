#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// const bool debug = false;

int arr[SIZE] = { 0 };

// O(sqrt(N))
bool isPrime(int n){
    if(n == 1) return false;
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
    int prime_cnt = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            prime_cnt++;
        }
    }
    cout << prime_cnt;

	return 0;
}

/* comment
- N <= 100, M = arr[i] <= 1000
- 소수 판별 함수 - O(sqrt(N))
- 총 시간복잡도 - O(N sqrt(M)) -> 가능.
 */