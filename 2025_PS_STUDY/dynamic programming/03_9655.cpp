#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    (n % 2 == 0) ? cout << "CY" : cout << "SK";

	return 0;
}


/* comment - 250202
- 게임 이론으로 푸는 방법, DP로 푸는 방법이 있음
게임 이론:
    경우를 나눠보면 1~6까지만 해보면 짝수: 후공이 이기고 홀수: 선공이 이김
    최초에 이렇게 제출함 -> 통과

DP:

*/