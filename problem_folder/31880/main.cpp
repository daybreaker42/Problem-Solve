#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 12
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    int arr_n[SIZE], arr_m[SIZE];
    for (int i = 0; i < n; i++)
    {
        cin >> arr_n[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr_m[i];
    }
    
    // solving
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr_n[i];
    }
    for (int i = 0; i < m; i++)
    {
        if(arr_m[i] != 0){
            ans *= arr_m[i];
        }
    }

    cout << ans;
    

	return 0;
}

/* comment 
bi 0 -> 맨 처음에 다 소모
bi 1 -> 상관 x
나머지에선 ai 다 더하고, bi 다 곱하는게 맞지 않나?


*/