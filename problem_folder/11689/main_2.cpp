#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000000001
#define ll long long
using namespace std;

// globals
// bool available[SIZE];    // 125 TB -> 이렇게 하는거 아닌듯
vector<int> n_prime_dividor;

// functions
void find_prime_dividor(ll n);
ll prime_comb(ll n, ll k, int idx);

// bool isAvailable(ll n);

int main() {
	fastio;
    ll n;
    cin >> n;
    
    // solving
    ll ans = 1;                     // 1 -> 무조건 정답
    // if(n > 1) ans--;             // n > 1이면 n은 정답 아님
    // available[1] = true;

    find_prime_dividor(n);
    ans += n - max((ll)0, prime_comb(n, 1, 0)) - 1;
    
    // output
    cout << ans;
	return 0;
}

// n 소인수분해
void find_prime_dividor(ll n){
    if(n % 2 == 0){
        n_prime_dividor.push_back(2);
        while((n & 1) == 0){
            n >>= 1;
        }
    }

    for(int i = 3; i <= n; i++){
        if(n % i == 0){
            n_prime_dividor.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    return;
}

// 2~ n-1까지 GCD(n, k) == 1이 아닌 것들만 셈
ll prime_comb(ll n, ll k, int idx){
    if(k >= n) return -1;     // 1일경우 -> 어차피 밖에서 ans=n해줘서 여기선 따로 안해도 됨.
    ll result = k > 1;
    // if(k == 1) result--;
    // else cout << "find - " << k << "\n";

    for(int i = idx; i < n_prime_dividor.size(); i++){
        ll returnVal;
        returnVal = prime_comb(n, k * n_prime_dividor[i], i);
        if(returnVal < 0) break;
        else result += returnVal;
    }
    
    return result;
}

/* comment
1~n에서 n의 서로소의 개수를 구하는 문제 (n > 1이면 n은 정답 아님.)

1) 에라토스테네스의 체처럼 available[] 만들어 해결
-> SIZE <= 10^12 -> 1비트씩 저장한다고 해도 약 125GB -> 이렇게 하는거 아닌듯

2) 차라리 소인수 리스트 구한 다음 (O(logn)~O(sqrt(n)))
해당 소인수 조합으로 만들 수 있는 수의 개수를 n에서 빼는건?
이렇게 된다면 소인수의 곱으로 나올 수 있는 최대 수 => 10^12*10^6 = 10^18로 대충 long long 범위 내에서 연산 가능
-> 이 방법대로 하면 소인수들의 곱으로만 나올 수 있는 조합만을 빼게 됨.
- 우리가 구해야 하는건 n의 소인수로 만들 수 있는 1~n까지의 모든 조합
- 그렇다고 에라토스테네스 하는건 말이 안되고..
*/