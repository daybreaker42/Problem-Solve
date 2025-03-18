#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;
    // freopen("../../input.txt", "r", stdin);
    bool isTree = true;
    int u, v, testcaseNum = 1;
    map<int, int> inbound;
    while(true){
        cin >> u >> v;
        // 프로그램 종료
        if(u < 0) break;
        // 케이스 종료
        if(u == 0){
            // 검사
            int rootNum = 0;

            for(const pair<int, int>& node : inbound){
                if(inbound[node.first] == 0) rootNum++;
                else if(inbound[node.first] > 1) isTree = false;
                if(!isTree) break;  // 더 볼 필요 없음
            }
            if(rootNum != 1) isTree = false;

            // 아무것도 없는 경우 -> 트리임
            if(inbound.size() == 0) isTree = true;

            // 결과 출력
            if(isTree){
                cout << "Case " << testcaseNum << " is a tree.\n";
            }else{
                cout << "Case " << testcaseNum << " is not a tree.\n";
            }

            // 초기화
            inbound.clear();
            isTree = true;
            testcaseNum++;
        }else{
            // u -> v, inbound 개수 추가
            inbound[u];
            inbound[v]++;
        }
    }

	return 0;
}

/* comment - 250313
- 들어오는게 2개 이상이면 안됨
- 스스로 들어오는거 있으면 안됨
- 정확히 1개만 들어오는거 없어야함, 2개 이상 or 0개면 x

* 노드 없는 경우 조심!! 안될땐 엣지 케이스 & 문제 조건 다시 봐보기
*/