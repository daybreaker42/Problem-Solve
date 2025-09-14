#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10
#define MAX 3000
using namespace std;

// const bool debug = false;

typedef struct{
    int x;
    int y;
}point;


int minCost;
int garden[SIZE][SIZE];

point selected[3];


// selected 장소 cost 합 계산
int calcCost(){
    int total = 0;
    point delta[4] = {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1},
    };
    for(int i = 0; i < 3; i++){
        int x = selected[i].x, y = selected[i].y;
        for(int j = 0; j < 4; j++){
            int nx = x + delta[j].x, ny = y + delta[j].y;
            total += garden[ny][nx];
        }
        total += garden[y][x];
    }
    return total;
}

void selectPosition(int n, int left){
    int selectedPositionNum = 3 - left;
    if(left == 0){
        minCost = min(minCost, calcCost());
        return;
    }
    
    for(int i = 1; i < n - 1; i++){             // 1~ n - 2까지 반복
        for(int j = 1; j < n - 1; j++){
            // 가능한 자리인지 확인
            bool isValidPosition = true;
            for(int k = 0; k < selectedPositionNum; k++){
                int distDiff = abs(selected[k].x - j) + abs(selected[k].y - i);
                if(distDiff < 3) {
                    isValidPosition = false;
                    break;
                };
            }
            if(isValidPosition){
                // 가능하다면 고르고 다음 반복 진행
                selected[selectedPositionNum] = {j, i};
                selectPosition(n, left - 1);
            }
        }   
    }
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> garden[i][j];
        }
    }

    // solving
    selectPosition(n, 3);
    cout << minCost;
    return 0;
}

/* comment 



*/