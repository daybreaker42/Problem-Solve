#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define SIZE (int)1E7
#define MAX (ll)1E14
using namespace std;

// const bool debug = false;

bool isPrime[SIZE + 1] = {false};
void initPrimes(){
    fill(isPrime, isPrime + SIZE, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= SIZE; i++){
        if(isPrime[i]){
            for(int j = i * 2; j <= SIZE; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    ll startNum, endNum;
    cin >> startNum >> endNum;

    // solving
    ll count = 0;
    initPrimes();
    for(ll i = 2; i * i <= endNum; i++){   // 계산시 overflow 방지를 위해 i를 long long으로 선언
        if(isPrime[i]){
            ll targetPrime = i * i; // n >= 2이므로
            while(targetPrime <= endNum){
                // cout << targetPrime << "\n";
                if(startNum <= targetPrime) {
                    count++;
                }
                if(targetPrime > LLONG_MAX / i) {    // long long overflow 방지
                    break;
                }
                targetPrime *= i;
            }
        }
    }
    cout << count;

	return 0;
}

/* comment - 250201
- 소수의 n제곱꼴 (n >= 2)인 수의 개수를 구하면 됨
- 범위가 10^14까지 -> 전부 일일히 확인은 불가. 에라토스테네스의 체를 여기까지 만드는것도 메모리제한때문에 불가.
- 대신 10^7까지만 소수 확인하고, 각 소수별로 SIZE를 넘어갈 때까지 범위 내 몇개가 있는지 확인하는게 빠를듯.

주의
- long long 범위 -> overflow에 유의
    방지하는법 ->> !(targetPrime < targetPrime * i) 대신 targetPrime > LLONG_MAX / i - 나눗셈 사용!!
*/