#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// const bool debug = false;


int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<stack<int>> stackArr(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            stackArr[j].push(num);
        }
    }

    // solving
    priority_queue<pair<int, int>> pq;          // {board 수, stack 번호}
    for(int i = 0; i < n; i++){
        pq.push({stackArr[i].top(), i});
        stackArr[i].pop();
    }
    for(int i = 0; i < n - 1; i++){
        int num, idx;
        tie(num, idx) = pq.top();
        pq.pop();
        pq.push({stackArr[idx].top(), idx});
        stackArr[idx].pop();
    }
    cout << pq.top().first;

    return 0;
}

/* comment

- 우선순위 큐 사용, 맨 끝에 있는 수들 일단 담고, n-1번 반복하면서 가장 큰 수는 빼고, 그 다음 줄에 있는 수들 중 가장 큰 수 집어넣음 -> 반복 -> 마지막에 남은 수 출력
-> 삽입/삭제 - O(logN) / 반복 N-1번 -> O(NlogN)
*/