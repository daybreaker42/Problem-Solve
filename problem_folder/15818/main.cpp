#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long result = 1;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        result *= val % m;
        result %= m;
    }
    cout << result;
}