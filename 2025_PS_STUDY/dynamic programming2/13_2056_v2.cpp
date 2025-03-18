#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> finish_time(n);
    vector<int> work_time(n);
    vector<vector<int>> sub_works(n);           // 이전에 오는 node 포인트
    vector<vector<int>> next_node(n);           // 다음에 가는 node 포인트

    queue<int> q;                               // 위상정렬시 사용, input node개수 0인것들 넣는 큐
    for (int i = 0; i < n; i++){
        cin >> work_time[i];
        int work_num;
        cin >> work_num;
        for (int j = 0; j < work_num; j++){
            int prev;
            cin >> prev; prev--;
            sub_works[i].push_back(prev);
            next_node[prev].push_back(i);
        }
    }
    
    // solving
    int ans;
    vector<int> input_node_num(n);
    for (int i = 0; i < n; i++){
        input_node_num[i] = sub_works[i].size();
        if(input_node_num[i] == 0){
            q.push(i);
        }
    }
    
    // 위상정렬하면서 작업 시간 구함
    while(!q.empty()){
        int curr = q.front(), maxValue = 0;
        q.pop();
        // 다음 연결 끊기
        for (int i = 0; i < next_node[curr].size(); i++){
            int next = next_node[curr][i];
            input_node_num[next]--;
            if(input_node_num[next] == 0){
                q.push(next);
            }
        }
        // 이전 연결된거 계산
        for(int i = 0; i < sub_works[curr].size(); i++){
            int prev = sub_works[curr][i];
            maxValue = max(maxValue, finish_time[prev]);
        }
        finish_time[curr] = maxValue + work_time[curr];
    }

    // output
    ans = finish_time[0];
    for (int i = 1; i < n; i++){
        ans = max(ans, finish_time[i]);
    }
    
    cout << ans;

	return 0;
}

/* comment - 250215 - 위상정렬을 이용한 버전
- sub_works는 이전 노드 정보만을 담고있어서 다음 노드 정보를 담고 있는 next_node가 필요했음
- 그리고 next_node에서 pop하기 애매해서 input_node_num만들어서 개수만 --하는식으로 input 간선 관리

*/