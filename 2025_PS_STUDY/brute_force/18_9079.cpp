#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;
bool coins[3][3];   // head = true, tail = false;


// type - 1~8 int
void flip(int type, bool target[3][3]){
    switch(type){
        case 1:
        // r1 뒤집기
        case 2:
        // r2 뒤집기
        case 3:
        // r3 뒤집기
        for(int i = 0; i < 3; i++){
            target[type - 1][i] = 1 - target[type - 1][i];
        }
        break;
        case 4:
        // c1 뒤집기
        case 5:
        // c2 뒤집기
        case 6:
        // c3 뒤집기
        for(int i = 0; i < 3; i++){
            target[i][type - 4] = 1 - target[i][type - 4];
        }
        break;
        case 7:
        // \ 뒤집기
        for(int i = 0; i < 3; i++){
            target[i][i] = 1 - target[i][i];
        }
        break;
        case 8:
        // / 뒤집기
        for(int i = 0; i < 3; i++){
            target[i][2 - i] = 1 - target[i][2 - i];
        }
        break;

    }
}

// 제대로 다 만들어졌나 체크
bool isSuccess(bool target[3][3]){
    int type_ = target[0][0];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(target[i][j] != type_) return false;
        }
    }
    return true;
}

void printArr(bool target[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << target[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t; cin >> t;
    char c;
    while(t-- > 0){
        // coins init
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> c;
                coins[i][j] = c == 'H';
            }
        }
        
        // solving
        // 256가지의 경우의 수 모두 테스트, 최대 7번임. (8번 뒤집기는 처음과 동일)
        int ans = -1;
        for(int i = 0; i < pow(2, 8); i++){
            bitset<8> isFlip(i);
            // 만약에 5회 이상 flip이 일어나면 pass
            int flipTotal = 0;
            for(int j = 0; j < 8; j++){
                if(isFlip[j]) flipTotal++;
            }
            if(flipTotal > 4) continue;

            // 아니면 진행
            bool afterFlippedCoins[3][3];   // coins[][] 여기에 복사됨
            for(int r = 0; r < 3; r++){
                for(int c = 0; c < 3; c++){
                    afterFlippedCoins[r][c] = coins[r][c];
                }   
            }
            for(int idx = 0; idx < 8; idx++){
                if(isFlip[idx]){
                    flip(idx + 1, afterFlippedCoins);
                    // cout << "==== 갱신 ====" << endl;
                    // printArr(afterFlippedCoins);
                    // cout << "============" << endl;
                }
            }
            // cout << "==== 결과 ====" << endl;
            // printArr(afterFlippedCoins);
            // cout << "============" << endl;

            if(isSuccess(afterFlippedCoins)){
                if(ans < 0 || ans > flipTotal) {
                    ans = flipTotal;
                }
            }
        }
        cout << ans << "\n";
    }
	return 0;
}

/* comment 250503
- 일단 brute force문제인데, brute force로 접근
- 한 칸을 두 번 뒤집기 -> 결과 동일
- 1행, 3행을 뒤집는거 = 2행만 뒤집는거 / H아니면 T로 통일되어야 하니까 차이 없음. -> 1, 3행 뒤집는걸 2행만 뒤집는걸로 생략 가능?
- 한 횟수에 가능한 모든 연산 = 8개 (3행, 3열, 대각선 2개)
-> 그렇다면, 가능한 모든 연산의 횟수 = 2^8번 (다 뒤집기~다 안 뒤집기 / 서로 대칭 구조를 가지고 있어서 그 절반만 해도 됨.)
- 연산의 순서는 상관 x
- 중복된 연산은 의미 x = 안한 거랑 동일
-> 가능한 모든 연산의 개수가 최대 256 (중복 제외 128)개밖에 없기 때문에 brute force로 가능할 듯

- 5번 이상 뒤집는건, 4번 이하 뒤집기와 동일하지 않나?

*/