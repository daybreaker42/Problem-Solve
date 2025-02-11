#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 50
using namespace std;

// const bool debug = false;

int targetLoc[NUM];

int findTargetIdx(int n, deque<int>& dq){
    int targetIdx;
    for(int i = 0; i < dq.size(); i++){
        if(dq[i] == n){
            targetIdx = i;
            break;
        }
    }
    return targetIdx;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, popNum;
    deque<int> dq(n);
    cin >> n >> popNum;
    for (int i = 0; i < n; i++){
        cin >> targetLoc[i];
    }

    for(int i = 0; i < n; i++) dq.push_back(i + 1);
    
    // solving
    sort(targetLoc, targetLoc + n);
    int operNum = 0;
    for(int i = 0; i < popNum; i++){
        int target = targetLoc[i];

        // find target idx
        int targetIdx = findTargetIdx(target, dq);        

        // operNum +=
        if(targetIdx == dq.size() - 1 - targetIdx && i < popNum - 1){   // 마지막연산이면 상관 x
            int nextTargetIdx = findTargetIdx(targetLoc[i + 1], dq);
            int dist = abs(nextTargetIdx - targetIdx);
            int alpha = nextTargetIdx < targetIdx ? -1 : 1; // 현재 target을 뺐을 때 nextTarget과의 위치관계에 의해서 이동거리가 변화하는 값
            // 두 번 이상 같을 경우는 x (홀/짝때문)
            if(dist < dq.size() - 1 - dist + alpha){
                // 다음에 왼쪽으로 이동하는게 나을 경우
                operNum += dist;

            }else{

            }
        }else if(targetIdx > dq.size() - 1 - targetIdx){
            // 왼쪽으로 이동시키는게 이득

        }else{
            // 오른쪽으로 이동하는게 이득

        }
    }


    // output
    cout << operNum;

	return 0;
}

/* comment - 250211
그냥 큐 돌리면 되는거같은데... 나중에 풀기
*/