#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

// const bool debug = false;
int arr1[SIZE], arr2[SIZE], resultArr[SIZE * 2];

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin); 

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> arr2[i];
    }

    // solving
    int resultIdx = 0, idx1 = 0, idx2 = 0;
    while(idx1 < n && idx2 < m){
        if(arr1[idx1] < arr2[idx2]){
            resultArr[resultIdx++] = arr1[idx1++];
        }else{
            resultArr[resultIdx++] = arr2[idx2++];
        }
    }
    while(idx1 < n){
        resultArr[resultIdx++] = arr1[idx1++];
    }
    while(idx2 < m){
        resultArr[resultIdx++] = arr2[idx2++];
    }

    for(int i = 0; i < n + m; i++){
        cout << resultArr[i] << " ";
    }

	return 0;
}

/* comment 
두 배열을 각각 보면서 더 작은 쪽은 resultArr에 넣으면서 resultArr을 완성해감.
둘 중 한 쪽이 끝나면 나머지 한 쪽을 그냥 몰아서 resultArr에 넣어줌.

*/