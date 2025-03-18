#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1500 * 1500
using namespace std;

// const bool debug = false;

// int board[SIZE][SIZE];
int nums[SIZE];

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n * n; i++){
        cin >> nums[i];
    }

    // solving
    sort(nums, nums + n * n);
    cout << nums[n * n - n];

    return 0;
}

/* comment 
- brute force & sort -> 모든 수 배열에 담고 정렬
-> O(NlogN) -> N<=1500이면 될수도?
-> 실제로 되버림;;

- 우선순위 큐 사용, 맨 끝에 있는 수들 일단 담고, n-1번 반복하면서 가장 큰 수는 빼고, 그 다음 줄에 있는 수들 중 가장 큰 수 집어넣음 -> 반복 -> 마지막에 남은 수 출력
-> 삽입/삭제 - O(logN) / 반복 N-1번 -> O(NlogN)
*/