#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 5000000

int arr[SIZE] = {0};

using namespace std;

// 단순 정렬 문제 - 241214 solved
int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    sort(arr, arr + n);

    // output
    cout << arr[k - 1];

	return 0;
}