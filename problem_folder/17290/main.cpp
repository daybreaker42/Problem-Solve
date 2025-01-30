#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// 위치 struct
struct loc{
    int x, y;
};

// functions
int dist(loc current, loc target);

int main() {
	fastio;
    loc player;
    cin >> player.y >> player.x;
    player.x -= 1;
    player.y -= 1;

    bool available_x[10]; // 폭탄이 존재하지 않는 x좌표 모음
    bool available_y[10]; // 폭탄이 존재하지 않는 y좌표 모음
    fill(available_x, available_x + 10, 1);
    fill(available_y, available_y + 10, 1);

    for(int i = 0; i < 10; i++){
        string c;
        cin >> c;
        for(int j = 0; j < 10; j++){
            if(c[j] == 'o'){
                available_x[j] = 0;
                available_y[i] = 0;
            }
        }
    }

    // solving
    int ans = 999;  // set to random maximum number
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(available_x[j] && available_y[i]){
                loc target = {j, i};
                ans = min(ans, dist(player, target));
            }
        }
    }

    // output
    cout << ans;

	return 0;
}

// 해당 지점까지의 거리 구하는 함수
int dist(loc current, loc target){
    return abs(target.x - current.x) + abs(target.y - current.y);
}