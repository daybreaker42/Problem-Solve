#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const bool debug = false;

int main() {
    fastio;
    int n;
    cin >> n;
    
    // 최대 힙과 최소 힙 선언
    priority_queue<int> maxHeap;                             // 왼쪽 부분(작은 수들)
    priority_queue<int, vector<int>, greater<int>> minHeap;  // 오른쪽 부분(큰 수들)
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        // 삽입 규칙: 최대 힙의 크기는 최소 힙의 크기와 같거나 하나 더 큼
        if(maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
        
        // 크기 균형 조정
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        // 중앙값 출력 (항상 maxHeap의 top)
        cout << maxHeap.top() << '\n';
    }
    
    return 0;
}