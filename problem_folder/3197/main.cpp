#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1500
using namespace std;

const bool debug = false;

struct point{
    int x = -1, y = -1;
};


int r, c;
char lake[SIZE][SIZE];
bool visited[SIZE][SIZE];

// functions
bool dfs(point curr);
void meltIce();
void printLake();

int main() {
	fastio;
    cin >> r >> c;

    point p1, p2;
    cin.ignore();
    for(int i = 0; i < r; i++){
        string str;
        getline(cin, str);
        for(int j = 0; j < c; j++){
            lake[r][c] = str[c];
            if(lake[r][c] == 'L'){
                if(p1.x == -1 && p1.y == -1){
                    p1 = {c, r};
                }else{
                    p2 = {c, r};
                }
            }
        }   
    }

    // solving
    int ans = 0;
    printLake();
    // while(true){
    //     // init
    //     memset(visited, 0, sizeof(visited));

    //     printLake();
    //     if(dfs(p1)){
    //         break;
    //     }
    //     ans++;
    //     meltIce();
    // }

    // cout << ans;

	return 0;
}

bool dfs(point curr){
    point delta[4] = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };

    visited[curr.y][curr.x] = true;
    if(lake[curr.y][curr.x] == 'L') return true;
    for(int i = 0; i < 4; i++){
        point newPoint = {curr.x + delta[i].x, curr.y + delta[i].y};
        if(0 <= newPoint.x && newPoint.x < c && 0 <= newPoint.y && newPoint.y < r){
            if(lake[newPoint.y][newPoint.x] != 'X'){
                dfs(newPoint);
            }
        }
    }
    return false;
}

// O(N^2)
void meltIce(){
    point curr;
    point delta[4] = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            curr = {j, i};
            if(lake[curr.y][curr.x] == 'X'){
                // 얼음일때
                for(int k = 0; k < 4; k++){
                    point newPoint = {curr.x + delta[k].x, curr.y + delta[k].y};
                    if(0 <= newPoint.x && newPoint.x < c && 0 <= newPoint.y && newPoint.y < r){
                        if(lake[newPoint.y][newPoint.x] == '.'){
                            // 물이 옆에 있다면
                            lake[curr.y][curr.x] = '.';
                            break;
                        }
                    }
                }
            }
        }   
    }
}

void printLake(){
    cout << "====================================\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << lake[i][j];
        }
        cout << "\n";
    }
    cout << "====================================\n";
    cout << "\n";
    return;
}