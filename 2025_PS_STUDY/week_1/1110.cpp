#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    // solving
    int val1 = n;
    int cycleCount = 0;

    while(cycleCount == 0 || val1 != n){
        int val2 = val1 / 10 + val1 % 10;
        val1 = val1 % 10 * 10 + val2 % 10;
        cycleCount++;
    }

    cout << cycleCount;

	return 0;
}

/** comment
 * 규칙에 따라 cycle을 돌리면서 처음 n이랑 같은지 체크하면 되는 문제
 */