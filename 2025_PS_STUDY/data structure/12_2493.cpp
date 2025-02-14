#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500000
using namespace std;

// const bool debug = false;

int height[SIZE];
int ans[SIZE];

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> height[i];
    }
    
    // solving
    stack<int> s;
    for(int i = n - 1; i >= 0; i--){
        // 왼쪽에 있는 탑이 크거나 같은 경우
        while(!s.empty() && height[i] >= height[s.top()]){
            // 왼쪽에 있는 탑보다 더 큰 값이 나올때까지 pop하면서 정답 기록
            ans[s.top()] = i + 1;   // 현재 번호 = 오른쪽에 있는 탑이 수신하는 탑
            s.pop();
        }
        s.push(i);
    }

    // output
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    
	return 0;
}

/* comment 
- 비슷한 문제 - 22866 탑 보기

결국 자신보다 더 큰 값이 올때까지 스택에 넣으면서 반복.
- stack이 비어있으면 해당 수 집어넣음.
- 스택에 값이 있으면 비교
    - 자신보다 크면 정답 기록 후 pop. 다음 number push
    - 작으면 그대로 push

*/