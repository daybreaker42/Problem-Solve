#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 16384  // 2^14, h < log2(10000) = log(10000) / log(2) < 14
using namespace std;

// const bool debug = false;
int tree[SIZE];

void postOrder(int curr){
    if(tree[curr * 2] > 0) postOrder(curr * 2); // 근데 계속 커지고 n = 10000이면 curr는 얼마까지 증가?
    if(tree[curr * 2 + 1] > 0) postOrder(curr * 2 + 1);
    cout << curr << "\n";
}

int main() {
	fastio;

	freopen("../../input.txt", "r", stdin);
    int val, root = -1;
    stack<pair<int, int>> s;
    while(cin >> val){
        if(root < 0) {
            // 루트 노드
            root = val;
            s.push({val, 1});
            tree[1] = val;
        }else{
            pair<int, int> t = s.top();
            if(val < t.first){
                // 숫자가 작음 - 왼쪽 노드
                int idx = t.second * 2;
                s.push({val, idx});
                tree[idx] = val;
            }else{
                // 숫자가 큼 - 오른쪽 노드
                s.pop();
                while(!s.empty() && s.top().first < val){
                    t = s.top();
                    s.pop();
                }
                // if(!s.empty()){
                //     // 오른쪽 노드 추가시 해당 노드는 더이상 자식 추가 불가
                //     s.push(t);  // 필요한가?
                // }
                int idx = t.second * 2 + 1;
                s.push({val, idx});
                tree[idx] = val;
            }   
        }
    }

    // solving
    postOrder(root);

	return 0;
}

/* comment 
- 이진 탐색트리를 전위순회한(dfs)결과로 후위순회 결과를 출력해내는 프로그램

* BST 중위순회 -> 오름차순 정렬임
*/