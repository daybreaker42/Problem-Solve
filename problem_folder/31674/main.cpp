#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 200000
#define MAGIC_NUM 1000000007

using namespace std;

// const bool debug = false;
int heightArr[SIZE];        // 키 정보 저장하는 배열
int expMemArr[SIZE + 1];    // getExp(N)의 결과를 저장하는 배열

// 2^exp의 mod된 결과를 반환하는 함수
// O(N)
// return값 10^9 + 7 이하
int getExp(int exp){
    int ans = 1;
    if(expMemArr[exp] >= 0) return expMemArr[exp];
    if(exp <= 1) return expMemArr[exp] = 1 << exp;    // 2 * getExp() * getExp() <= 2^29

    if(exp % 2 == 0){
        return expMemArr[exp] = (long long)getExp(exp / 2) * getExp(exp / 2) % MAGIC_NUM;
    }else{
        return expMemArr[exp] = (long long)getExp(exp / 2) * getExp(exp / 2) * 2 % MAGIC_NUM;
    }
}


int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> heightArr[i];
    }

    // solving
    memset(expMemArr, -1, (SIZE + 1) * sizeof(expMemArr[0])); // -1로 초기화
    sort(heightArr, heightArr + n, greater<int>()); // 내림차순 정렬

    int ans = 0;
    for(int i = 0; i < n; i++){
        int iterVal = 0;
        int exp = max(0, (i - 1));  // 지수
        for(int j = 0; j <= i; j++){
            
            iterVal += (long long)heightArr[j] * getExp(exp) % MAGIC_NUM;
            iterVal %= MAGIC_NUM;
            exp = max(0, exp - 1);
        }
        ans += iterVal;
        ans %= MAGIC_NUM;
    }
    cout << ans;
    


	return 0;
}

/* comment 
1. brute force 안됨
2. 


*/