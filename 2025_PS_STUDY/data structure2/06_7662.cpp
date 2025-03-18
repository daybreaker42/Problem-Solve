#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

void remove_max_q(int val, priority_queue<int>& max_q, map<int, int>& max_q_to_delete){
    if(!max_q.empty()){
        if(max_q.top() == val){
            // 바로 찾았다면 바로 제거
            max_q.pop();
        }else{
            // 아니라면 일단 to delete에 등록
            if(max_q_to_delete.find(val) != max_q_to_delete.end()){
                max_q_to_delete[val]++;
            }else{
                max_q_to_delete[val] = 1;
            }
        }
    }
}

void remove_min_q(int val, priority_queue<int, vector<int>, greater<int>>& min_q, map<int, int>& min_q_to_delete){
    if(!min_q.empty()){
        if(min_q.top() == val){
            // 바로 찾았다면 바로 제거
            min_q.pop();
        }else{
            // 아니라면 일단 to delete에 등록
            if(min_q_to_delete.find(val) != min_q_to_delete.end()){
                min_q_to_delete[val]++;
            }else{
                min_q_to_delete[val] = 1;
            }
        }
    }
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t-- > 0){
        int k;
        cin >> k;
        priority_queue<int> max_q;      // 최댓값 저장 - max heap
        priority_queue<int, vector<int>, greater<int>> min_q;   // 최솟값 저장 - min heap
        map<int, int> max_q_to_delete, min_q_to_delete;
        
        while(k-- > 0){
            char c;
            int n;
            cin >> c >> n;
            if(c == 'D'){
                // if()     // 큐에 값이 있는 경우만 삭제
                if(n > 0){
                    // 최댓값 삭제
                    while(!max_q_to_delete.empty() && max_q_to_delete.find(max_q.top()) != max_q_to_delete.end()){
                        remove_max_q(max_q.top(), max_q, max_q_to_delete);
                    }
                    if(!max_q.empty()){
                        int max_num = max_q.top();
                        remove_max_q(max_q.top(), max_q, max_q_to_delete);
                        remove_min_q(max_num, min_q, min_q_to_delete);
                    }else if(!min_q.empty()){
                        // max q가 비었음 -> min_q도 비어있어야 함
                        while(!min_q.empty()) min_q.pop();
                    }
                }else{
                    // 최솟값 삭제
                    while(!min_q_to_delete.empty() && min_q_to_delete.find(min_q.top()) != min_q_to_delete.end()){
                        remove_min_q(min_q.top(), min_q, min_q_to_delete);
                    }
                    if(!min_q.empty()){
                        int min_num = min_q.top();
                        remove_min_q(min_q.top(), min_q, min_q_to_delete);
                        remove_max_q(min_num, max_q, max_q_to_delete);
                    }else if(!max_q.empty()){
                        while(!max_q.empty()) max_q.pop();
                    }
                }
            }else{
                // 삽입
                // max heap 검사
                if(!max_q_to_delete.empty() && max_q_to_delete.find(n) == max_q_to_delete.end()){
                    max_q.push(n);
                }else{
                    if(max_q_to_delete[n] > 1){
                        max_q_to_delete[n]--;
                    }else{
                        max_q_to_delete.erase(n);
                    }
                }
                // min heap 검사
                if(!min_q_to_delete.empty() && min_q_to_delete.find(n) == min_q_to_delete.end()){
                    min_q.push(n);
                }{
                    if(min_q_to_delete[n] > 1){
                        min_q_to_delete[n]--;
                    }else{
                        min_q_to_delete.erase(n);
                    }
                }
            }

            while(max_q_to_delete.size() > 0){
                
            }

            // 큐에 값이 없으면 EMPTY 출력
            // 있다면 최대/최솟값 출력
        }
    }

	return 0;
}

/* comment - 250302
- 우선순위 큐 두개 사용, 밀리는 연산은 큐마다 map만들어 처리 못한 숫자들 저장
- 삭제시 해당 수가 map에 있는지 각각 확인 후 삭제
    - map에 있다면 해당 수는 바로 삭제 (횟수 0이상이면 -1, 0이면 삭제)
- insert시 map에 있는지 확인 후 삽입
    - 있다면 map에서만 제거
- map엔 {해당 수, 제거 횟수} 저장.

- c++에서 map은 균형이진트리로 구현돼있음 -> 그냥 이걸로 삽입/삭제 하면 양방향 큐 되는거 아님??
*/