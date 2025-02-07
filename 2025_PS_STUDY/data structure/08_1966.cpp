#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while(t-- > 0){
        int n, targetIdx, idx = 0;  // idx - sort_priority에서 현재 남아있는 수들 중 가장 중요도가 큰 수 가리킴
        cin >> n >> targetIdx;
        vector<int> sort_priority(n);
        vector<pii> priority(n);  // {중요도, 원래 순서}
        queue<pii> printer;
        for(int i = 0; i < n; i++){
            cin >> priority[i].first;
            priority[i].second = i;
            printer.push(priority[i]);
            sort_priority[i] = priority[i].first;
        }
        // solving
        sort(sort_priority.begin(), sort_priority.end(), greater<>());

        int count = 1, maxPriority = sort_priority[idx];
        while(printer.front().second != targetIdx || maxPriority != printer.front().first){    // printer != {sort_priotity[idx].first, targetIdx} 일때
            if(printer.front().first == maxPriority){
                count++;
                idx++;
                maxPriority = sort_priority[idx];
            }else{
                printer.push(printer.front());
            }
            printer.pop();
        }
        cout << count << "\n";
    }

	return 0;
}

/* comment 250208
idea)
1. 정렬된 중요도 리스트를 하나 만들어 가장 중요도가 높은 요소 순서대로 관리
2. 가장 중요한 요소가 나올때까지 큐를 돌림
3. 나왔는데 우리가 찾는게 아니라면 순서 + 1 하고 계속 반복


Q) 그냥 정렬하면 안되냐?
A) stable sort의 경우, 1 1 9 1 1 1 일때 같은 중요도인 문서에 대해 잘못된 순서를 밷을 수 있음
ex) m=2일때 stable sort하면 3이 되는데 정답은 6(마지막)임
*/