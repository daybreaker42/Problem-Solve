#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
using namespace std;

// const bool debug = false;
int tired[SIZE];

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int p, n; cin >> p >> n;
    for(int i = 0; i < n; i++){
        cin >> tired[i];
    }

    // solving
    int leftTired = 200 - p;
    sort(tired, tired + n);
    int idx = 0, ans = 0;
    // for(int i = 0; i < n; i++) cout << tired[i] << " ";
    // cout << endl;
    while(leftTired > 0 && idx < n){
        leftTired -= tired[idx++];
        ans++;
    }
    cout << ans;

	return 0;
}

/* comment 250501
- greedy
- 최대 개수 최소 피로도 -> 피로도 작은 것부터 추가!

*/