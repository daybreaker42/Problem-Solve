#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 1000000009
#define SIZE 100000
using namespace std;

// const bool debug = false;

int arr[SIZE + 1][3];

int mod3(int n){
    return (n + 3) % 3;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int t, n;
    cin >> t;
    // init array
    arr[1][0] = 1;
    arr[2][1] = 1;
    arr[3][2] = 1;
    for(int i = 3; i <= SIZE; i++){
        for(int idx = 0; idx < 3; idx++){
            arr[i][idx] += arr[i - idx - 1][mod3(idx + 1)];
            arr[i][idx] %= NUM;
            arr[i][idx] += arr[i - idx - 1][mod3(idx - 1)];
            arr[i][idx] %= NUM;
        }
    }

    while(t-- > 0){
        cin >> n;
        
        // // output test
        // for(int j = 0; j < 3; j++){
        //     for(int i = 1; i <= n; i++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "----\n";

        int result = 0;
        for(int i = 0; i < 3; i++){
            result += arr[n][i];
            result %= NUM;
        }
        cout << result << "\n";

    }

	return 0;
}

/* comment - 250202
주요 idea
- 이전에 사용했던 숫자 기억해서 dp 하는거
- 어차피 결과 배열은 n이 얼마든 동일하니까 한번 만들어놓고 계속 사용 (안그러면 시간초과)
*/