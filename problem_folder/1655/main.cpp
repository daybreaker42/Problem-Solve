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
    int higher = 0, lower = 0;
    int midVal = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(i == 0){
            midVal = val;
            cout << midVal << "\n";
            continue;
        }
        if(higher > lower){
            // lower_q < higher_q -> lower_q에 삽입해야함
            if(val <= midVal){
                // val <= midVal <= higher_q.top()
                lower_q.push(val);
            }else if(val <= -higher_q.top()){
                // midVal < val <= higher_q.top()
                lower_q.push(midVal);
                midVal = val;
            }else{
                // higher_q.top() < val
                lower_q.push(midVal);
                midVal = -higher_q.top();
                higher_q.pop();
                higher_q.push(-val);
            }
            lower++;
        }else{
            // lower_q == higher_q -> higher_q에 삽입해야함
            if(lower > 0 && val < lower_q.top()){
                // val < lower_q.top()
                higher_q.push(-midVal);
                midVal = lower_q.top();
                lower_q.pop();
                lower_q.push(val);
            }else if(val < midVal){
                // lower_q.top() < val < midVal <= higher_q.top()
                higher_q.push(-midVal);
                midVal = val;
            }else{
                // midVal <= val, higher_q.top()
                higher_q.push(-val);
            }
            higher++;
        }
        cout << midVal << "\n";
    }

	return 0;
}
