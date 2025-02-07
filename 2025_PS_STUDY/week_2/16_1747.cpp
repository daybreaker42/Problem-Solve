#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

// O((log N)/2) ?
bool isPalidrome(int n){
    string str = to_string(n);
    int length = str.length();
    for(int i = 0; i < length / 2; i++){
        if(str[i] != str[length - 1 - i]) return false;
    }
    return true;
}

// O(sqrt(N))
bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    while(!isPalidrome(n) || !isPrime(n)){
        n++;
    }

    cout << n;

	return 0;
}

/* comment
- isPalidrome()이 더 시간복잡도상 유리할 것 같아 먼저 배치
- isPalidrome() && isPrime() 이 아닐 경우이므로 드 모르간 법칙 사용 -> notA or notB
- 조건이 더 있을 줄 알았는데 생각보다 간단했음

- 이전 python code -> 에라토스테네스의 체를 쓰는 중에 소수인지 판별
    - 1003001 -> 에라토스테네스의 체를 한번 사용한 결과 나오는 최대 다음 소수인듯?
    - 시간은 c++이 python 10배 (16ms vs 168ms)
- 꼭 에라토스테네스의 체를 쓰지 않아도 solve 가능
    - 관련 게시판 글 - https://www.acmicpc.net/board/view/129810
*/