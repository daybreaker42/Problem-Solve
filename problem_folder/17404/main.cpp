#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
#define INF 1000001
using namespace std;


/**
 * R = 0, G = 1, B = 2로 취급
 */
int houseCost[SIZE][3] = { 0 }; // 각 집마다 드는 비용 저장
int memory[SIZE][3][3] = { 0 }; // 각 집까지 드는 모든 경로의 비용 저장, 각각의 cell에선 1번 정보에 따라 3개씩 누적 cost 합 저장
// int firstInfo[SIZE][3] = { 0 }; // i=0번 노드를 어떤 걸 사용했는지를 저장하는 배열

int conv(int n);                // n을 항상 0~2 이내의 범위로 유지

void printArr(int n, int array[SIZE][3]);

int main() {
	fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> houseCost[i][0] >> houseCost[i][1] >> houseCost[i][2];
    }

    // solving
    // 1. memory 배열 초기화
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                memory[i][j][k] = INF;
            }
        }
    }
    
    // 2. memory 배열 채우기
    for(int x = 0; x < n; x++){
        for(int y = 0; y < 3; y++){
            if(x == 0){
                // 해당 번호 말곤 나머진 INF
                memory[x][y][y] = houseCost[x][y];
                // firstInfo[x][y] = y;
            }else if(x == n - 1){
                // n번째 집
                for(int firstIdx = 0; firstIdx < 3; firstIdx++){
                    if(firstIdx != y){
                        memory[x][y][firstIdx] = houseCost[x][y] + min(memory[x - 1][conv(y + 1)][firstIdx], memory[x - 1][conv(y - 1)][firstIdx]);
                    }
                }
            }else{
                // 2~n-1번쨰 집
                for(int firstIdx = 0; firstIdx < 3; firstIdx++){
                    memory[x][y][firstIdx] = houseCost[x][y] + min(memory[x - 1][conv(y + 1)][firstIdx], memory[x - 1][conv(y - 1)][firstIdx]);
                }
            }
        }
    }

    // output
    int result = INF;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result = min(result, memory[n - 1][i][j]);
        }
    }
    // cout << min(min(memory[n - 1][0], memory[n - 1][1]), memory[n - 1][2]);
    cout << result;

    // cout << "\n\n";
    //     for(int i = 0; i < n; i++){
    // for(int j = 0; j < 3; j++){
    //         for(int k = 0; k < 3; k++){
    //             cout << setw(7) << memory[i][j][k] << " ";
    //         }
    //         cout << "| ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}

int conv(int n){
    if(n < -1 || n > 3) throw out_of_range("Index out of range");
    if(n < 0) return n + 3;
    if(n >= 3) return n - 3;
    return n;
}

void printArr(int n, int array[SIZE][3]){
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < n; i++){
            if(j == 0){
                cout << "i=" << setw(4) << i << " ";
            }else{
                cout << setw(6) << array[i][j - 1] << " ";
            }
        }
        cout << "\n";
    }
    cout << "-----------------\n";
}