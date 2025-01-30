#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    short n, k;
    cin >> n >> k;

    // solving
    vector<bool> primeList(n + 1, true);

    for(int i = 2; i <= n; i++){
        if(primeList[i]){
            k--;    // P도 지우므로
            if(k == 0){
                cout << i;
                return 0;
            }
            for(int j = 2 * i; j <= n; j += i){
                if(primeList[j]){
                    primeList[j] = false;
                    k--;
                    if(k == 0){
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }


	return 0;
}

// comment
/*
- 원래 P는 안지우는데 그걸 따로 표시하는게 포인트
*/

// ai solution

/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fastio;
    
    int n, k;
    cin >> n >> k;
    
    // 에라토스테네스의 체 초기화
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;  // 0, 1은 제외
    
    int count = 0;  // 지워진 숫자 카운트
    
    // 에라토스테네스의 체 실행
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            // 현재 소수 처리
            count++;
            if(count == k) {
                cout << i;
                return 0;
            }
            
            // 현재 소수의 배수들 처리
            for(int j = i * 2; j <= n; j += i) {
                if(isPrime[j]) {
                    isPrime[j] = false;
                    count++;
                    if(count == k) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
    
    return 0;
}
*/