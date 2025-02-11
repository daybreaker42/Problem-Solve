#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
using namespace std;


// const bool debug = false;

int height[SIZE];              // 건물 높이 저장
int visible_count[SIZE];    // 건물당 볼 수 있는 건물 개수 저장
int near_building[SIZE];    // 가장 가까우면서 번호가 작은 빌딩 번호 저장

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int arr[] = {1, 2, 3, 4, 5};
    deque<int> dq(5);
    for(int i = 0; i < 5; i++){
        dq[i] = arr[i];
    }

    for(auto i : dq){
        cout << i << " ";
    }
}