#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;
int n, m;
int price[10];
int maxRoomNum[51];   // maxRoomNum[cost] -> cost로 만들 수 있는 최대 방 번호
int numUsedCnt[51][10];  // 각 cost에서 사용되었던 번호별 개수 저장

// 해당 cost의 maxRoomNum을 반환하는 함수
int getRoomNum(int cost){
    string str = "";
    // n - 1부터 0까지 차례대로 앞에 배치 -> n개 숫자로 가능한 최대 숫자
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < numUsedCnt[cost][i]; j++){
            str += to_string(i);
        }
    }
    return stoi(str);
}

// 실제로 cost로 만들 수 있는 최대호수를 만들 때 든 비용
int getTotalCost(int cost){
    int totalPrice = 0;
    for(int i = 0; i < n; i++){
        if(numUsedCnt[cost][i]){
            totalPrice += price[i] * numUsedCnt[cost][i];
        }
    }
    return totalPrice;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    cin >> m;

    // solving
    int ans;
    // 각 cost별로 순회하면서 만약 최대 room num을 갱신할 수 있다면 출력
    for(int curr = 1; curr <= m; curr++){
        for(int objIdx = 0; objIdx < n; objIdx++){
            int prev = curr - price[objIdx];
            if(prev < 0 || getTotalCost(prev) + price[objIdx] > curr) continue;   // 현재 가격에서 구매할 수 없었던거라면 pass

            numUsedCnt[prev][objIdx]++;
            if(maxRoomNum[curr] < getRoomNum(prev)){
                maxRoomNum[curr] = getRoomNum(prev);
                // numUsedCnt[curr][objIdx]++;
                memmove(numUsedCnt[curr], numUsedCnt[prev], sizeof(int) * 10);
            }
            numUsedCnt[prev][objIdx]--;
        }
    }

    cout << getRoomNum(m);

    // cout << endl;
    // for(int i = 0; i <= m; i++){
    //     cout << maxRoomNum[i] << " ";
    // }
    // cout << endl;

    // system("pause");
    return 0;
}

/* comment 



*/