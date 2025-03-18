#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n;
    cin >> n;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(val > 0){
            pq.push(val);
        }else{
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }else{
                cout << 0 << "\n";
            }
        }
    }

	return 0;
}

/* comment - 250303
- 우선순위큐 사용하는 문제



*/