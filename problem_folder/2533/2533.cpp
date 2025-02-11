#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

bool checkSolved(int n, vector<int>& status);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<int> status(n, 0);   // 0 - 아이디어 x, 1 - 아이디어 o, 2 - 얼리어답터
    // vector<pair<int, int>> near_req_ea_num(n);  // {필요 ea 수, 번호}
    vector<vector<int>> node(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        node[u - 1].push_back(v - 1);
        node[v - 1].push_back(u - 1);
    }

    // solving
    priority_queue<pair<int, int>> near_req_ea_num;
    for(int i = 0; i < n; i++){
        // near_req_ea_num[i] = {node[i].size(), i};   // 처음엔 친구 수=필요ea수 - init
        near_req_ea_num.push({node[i].size(), i});
    }
    // sort(near_req_ea_num.begin(), near_req_ea_num.end(), greater<>());

    int idx = 0, start, minEANum = 0;    
    while(true){
        start = near_req_ea_num.top().second;
        status[start] = 2;
        minEANum++;
        cout << "EA - " << start + 1 << "\n";
        for(int idx : node[start]){ // 새로 생긴 얼리어답터의 주변만 check
            // if(status[idx] == 0) status[idx] = 1;
            bool ideaAcceptable = true;
            for(int eaIdx : node[idx]){
                if(status[eaIdx] != 2) {
                    ideaAcceptable = false;
                    break;
                }
            }
            if(ideaAcceptable){
                status[idx] = 1;
            }
        }

        if(checkSolved(n, status)) break;
        
        // while(status[near_req_ea_num[idx].second] != 0){
        //     idx++;
        // }
    }

    cout << minEANum;

	return 0;
}

bool checkSolved(int n, vector<int>& status){
    for(int i = 0; i < n; i++){
        if(status[i] == 0) return false;
    }
    return true;
}
    


/* comment - 250211

idea1)
아무 노드에서나 (1번 등) 시작하고, 해당 노드가 얼리어답터일 경우와 아닐 경우를 비교하면 됨.
특정 사람으로부터 시작해 해당 경우의 얼리어답터 수를 구하는 방법 -> dfs이용, 해당 노드가 얼리어답터인지의 정보만 주면 됨



ㄴ자신의 '모든' 친구가 얼리어답터야 함

idea2)
주변에 필요한 얼리어답터 수 -> 각 노드마다 구하기
- 해당 수가 많을수록, 번호가 적은 것부터 돌면서 얼리어답터로 변환 (결국 총 필요 얼리어답터수 = 0으로 만드는 가장 빠른 방법)
- 새로 얼리어답터 생길 시 그 주변 친구들의 '필요 주변 얼리어답터 개수' 줄이기
*/
