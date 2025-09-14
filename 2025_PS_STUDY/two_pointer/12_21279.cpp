#include <bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
#define SIZE 500000
using namespace std;

typedef struct mineral{
    int x;
    int y;
    int v;
};

bool compareByX(mineral a, mineral b){
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
bool compareByY(mineral a, mineral b){
    if(a.y == b.y) return a.x > b.x;
    return a.y < b.y;

}

int main(){
    fastio
    int n, c;
    cin >> n >> c;
    mineral mineralList[SIZE];
    for (int i = 0; i < n; i++)
    {
        cin >> mineralList[i].x >> mineralList[i].y >> mineralList[i].v;
    }
    
    // solving
    sort(mineralList, mineralList + n, compareByX);
    vector<vector<mineral>> mineralSortedX(n);      // x는 오름차순, 같은 y는 내림차순으로 정렬
    int xIdx = 0, xSize = 0;
    for(int i = 0; i < n; i++){
        mineralSortedX[xIdx].push_back(mineralList[i]);
        if(i != n - 1){
            if(mineralList[i + 1].x != mineralList[i].x){
                xIdx++;
            }
        }
    }
    xSize = xIdx + 1;
    sort(mineralList, mineralList + n, compareByY);
    vector<vector<mineral>> mineralSortedY(n);      // y 오름차순, 같은 x는 내림차순으로 정렬
    int yIdx = 0, ySize = 0;
    for(int i = 0; i < n; i++){
        mineralSortedX[yIdx].push_back(mineralList[i]);
        if(i != n - 1){
            if(mineralList[i + 1].y != mineralList[i].y){
                yIdx++;
            }
        }
    }
    ySize = yIdx + 1;

    

}

/* comment 250506
- x에 대해 정렬, 누적합 리스트 만들기
- y에 대해 정렬, 누적합 리승트 만들기
- x최대, y최소부터 시작해서 whlie(yIdx < n) -> 만약 개수가 c개 초과시 xIdx--

*/