#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100
#define ll long long
using namespace std;

int selection[MAX][3] = {0};
int selectCount[MAX] = {0};

const bool debug = true;    // debug mode

ll gcd(ll n, ll m);
ll hitProb(int x, int k, int m);
ll power(ll n, int k);

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    int tc = 3 * m; // total count
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < 3; j++){
            cin >> selection[i][j];
            selectCount[selection[i][j] - 1]++;
        }
    }

    // solving
    ll p = 1, q = 1;
    ll maxProb = 0;
    if(debug){
        cout << "count | ";
        for (int i = 0; i < n; i++)
        {
            cout << selectCount[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++){
        selectCount[i]++;
    }    

    for(int a = 1; a <= n; a++){
        for(int b = a + 1; b <= n; b++){
            for(int c = b + 1; c <= n; c++){
                ll x = tc - selectCount[a - 1] - selectCount[b - 1] - selectCount[c - 1];
                ll tmp = hitProb(x, k, m);
                if(maxProb < tmp){
                    // 갱신
                    maxProb = tmp;
                    p = tmp;
                    q = power(tc, k + 1);
                    p /= gcd(p, q);
                    q /= gcd(p, q);
                    selection[m - 1][0] = a;
                    selection[m - 1][1] = b;
                    selection[m - 1][2] = c;
                    if(debug){
                        cout << "최대확률갱신 - " << tmp << " | " << a << " " << b << " " << c << "\n";
                    }
                }
            }
        }
    }

    // output
    cout << p / gcd(p, q) << " " << q / gcd(p, q) << "\n";
    for(int i = 0; i < 3; i++){
        cout << selection[m - 1][i] << " ";
    }
	return 0;
}

ll gcd(ll n, ll m){
    if(m > n) swap(n, m);
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

// x^k(3*m - x)
ll hitProb(int x, int k, int m){
    ll result = 1;
    result = power(x, k);
    result *= (3 * m - x);
    return result;
}

ll power(ll n, int k){
    ll result = 1;
    for (int i = 0; i < k; i++){
        result *= n;
    }
    return result;
}