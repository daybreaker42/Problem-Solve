#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int gcd(int n, int m){
    if(n < m) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int t, numA, numB;
    cin >> t;
    while(t-- > 0){
        cin >> numA >> numB;
        cout << numA * numB / gcd(numA, numB) << "\n";
    }

	return 0;
}