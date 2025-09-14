#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 9
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int h, w, c; cin >> h >> w >> c;
    int ballNum[SIZE];
    for (int i = 0; i < c; i++)
    {
        cin >> ballNum[i];
    }

    // solving
    int idx = 0;
    int ans[10][10];
    for(int i = 0; i < h; i++){
        if(i % 2 == 0){
            // 좌 -> 우
            for(int j = 0; j < w; j++){
                ans[i][j] = idx + 1;
                if(--ballNum[idx] <= 0){
                    idx++;
                }
            }
        }else{
            // 우 -> 좌
            for(int j = w - 1; j >= 0; j--){
                ans[i][j] = idx + 1;
                if(--ballNum[idx] <= 0){
                    idx++;
                }
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ans[i][j];
        }
        cout << "\n";
    }
    

	return 0;
}

/* comment - 250513
- 해당 판에서 나올 수 있는 최대 점수 = 각 색깔별로 한번에 터지는거
-> 모든 색깔이 같은 색 안에서 한 묶음으로 이어지게 만들면 됨
-> ㄹ자로 가면서 색상 순차적으로 배치
*/