#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const bool debug = false;

int main() {
	fastio;
    int n;
    cin >> n;
    // higher_q - 최소힙, lower_q - 최대힙)
    priority_queue<int> higher_q, lower_q;   // 기본적으로 max_heap이므로 higher_q에 넣을땐 부호를 바꿔서 넣기

    // solving
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(i == 0){
            higher_q.push(-val);
            cout << val << "\n";
            continue;
        }
        
        if(lower_q.size() < higher_q.size()){
            
        }
    }

	return 0;
}
