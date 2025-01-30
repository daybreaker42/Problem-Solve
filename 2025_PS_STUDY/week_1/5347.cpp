#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

// const bool debug = false;

ll gcd(ll n, ll m){
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int t;
    ll numA, numB;
    cin >> t;
    while(t-- > 0){
        cin >> numA >> numB;
        cout << numA * numB / gcd(numA, numB) << "\n";
    }

	return 0;
}

/* comment
1934랑 같은 문제이지만, 숫자의 범위가 int를 넘어가 double을 사용해야 해결이 가능
*/