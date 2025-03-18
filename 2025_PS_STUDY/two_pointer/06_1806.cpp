#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll arr[100000];

ll getIntervalSum(int st, int ed);

int main(){

    // freopen("../../input.txt", "r", stdin);

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0){
            arr[i] += arr[i - 1];
        }
    }

    // solving
    int minLength = n + 1;
    int st = 0;
    for(int ed = 0; ed < n; ed++){
        ll intervalSum = getIntervalSum(st, ed);
        if(intervalSum >= s){
            minLength = min(minLength, ed - st + 1);
            while(st < ed && intervalSum){
                st++;
                intervalSum = getIntervalSum(st, ed);
                if(intervalSum >= s){
                    minLength = min(minLength, ed - st + 1);
                }else{
                    break;
                }
            }
        }
    }

    // output
    if(minLength > n) cout << 0;
    else cout << minLength;
}

ll getIntervalSum(int st, int ed){
    if(st == 0) return arr[ed];
    return arr[ed] - arr[st - 1];
}

/* comment - 250217
- 누적합 + brute force로 한다면? -> <= 5천만 -> 0.5초 아슬아슬..
ㄴ 시간 초과남.

- 투 포인터를 사용, 먼저 ed를 전진시키면서 s 이상의 구간합이 발견되면 s보다 작아질때까지 st를 증가시킴.
그 과정에서 구간합 s보다 크면 최소길이 업데이트
*/