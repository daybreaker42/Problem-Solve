#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int a, b, c; cin >> a >> b >> c;
    int ans = -1;
    if(b < c){
        ans = a / (c - b);
        ans += b % c > 0;
    }

    cout << ans;

	return 0;
}

/* comment 250521
- 물건의 가격 - 비용이 1 이상이면 고정비용을 해당 값으로 나눈 값을,
그렇제 않으면 -1을 출력
*/