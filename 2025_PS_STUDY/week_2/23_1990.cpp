#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE (int)1E7 + 1
using namespace std;

// const bool debug = false;

bool isPrime[SIZE] = {false};
int startNum, endNum;

bool isPalidrome(int n){
    string str = to_string(n);
    int len = str.length();
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - i - 1]){
            return false;
        }
    }
    return true;
}

void initPrimeList();

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    cin >> startNum >> endNum;

    initPrimeList();

    cout << -1;

	return 0;
}

void initPrimeList(){
    fill(isPrime, isPrime + SIZE, true);
    isPrime[1] = false;
    for(int i = 2; i <= SIZE; i++){
        if(isPrime[i]){
            if(startNum <= i && i <= endNum && isPalidrome(i)){
                cout << i << "\n";
            }
            // cout << i << "\n";
            for(int j = i * 2; j <= SIZE; j += i){
                isPrime[j] = false;
            }
        }
    }
}


/* comment 
1) 에라토스테네스 -> 10^9 하니까 메모리초과 (bool type이오도 1GB)
2) 제곱근으로 소수 판정 -> 시간초과
3) 에라토스테네스 범위 10^8으로 다시 설정해서 트라이 -> 시간초과
    - 최적화해서 다시 시도했는데도 안됨
    - 10^7 까지 SIZE 조절해서 하니까 됨. 왜지??
        - 최대 소수인 palidrome이 약 9백9십만 (9989899) -> 10^7 이하
*/