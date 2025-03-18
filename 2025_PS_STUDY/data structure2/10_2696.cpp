#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t-- > 0){
        int m;
        cin >> m;
        cout << m / 2 + m % 2 << "\n";
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<int>> upper;
        for(int i = 0; i < m; i++){
            int val;
            cin >> val;
            // upper는 항상 lower보다 같거나 큼
            if(i == 0){
                upper.push(val);
                cout << val << " ";
            }else if(lower.size() == upper.size()){
                // 홀수 번째일때
                if(lower.top() > val){
                    upper.push(lower.top());
                    lower.pop();
                    lower.push(val);
                }else{
                    upper.push(val);
                }
                // 홀수 번째일때 중앙값 출력
                cout << upper.top() << " ";
            }else{
                // 짝수 번째일떄
                if(upper.top() < val){
                    lower.push(upper.top());
                    upper.pop();
                    upper.push(val);
                }else{
                    lower.push(val);
                }
                if((i + 1) % 20 == 0) cout << "\n";
            }
        }
        cout << "\n";
    }

	return 0;
}

/* comment - 250312
- 중앙값 구하기 - 우선순위 큐 두개 두고 계산
한쪽을 다른쪽보다 크기 1차이로 유지하면서 계산
비슷한문제 이전에 했었음
*/