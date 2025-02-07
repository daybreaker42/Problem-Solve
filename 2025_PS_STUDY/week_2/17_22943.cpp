#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10
#define MAX 99999 + 1
using namespace std;

// const bool debug = false;

// O(sqrt(N))
// bool isPrime(int n){
//     if(n < 2) return false;
//     for(int i = 2; i * i <= n; i++){
//         if(n % i == 0) return false;
//     }
//     return true;
// }

bool isPrime[MAX] = {false};

void initPrimeList();

// 조건1: 서로 다른 두 소수의 합으로 나타낼 수 있는지
bool checkCondition1(int n){
    for(int i = 2; i <= n / 2; i++){
        if(i != n - i && isPrime[i] && isPrime[n - i]) return true;   // i < n / 2 이므로 서로 안겹침
    }
    return false;
}
// 조건2: M으로 나누어 떨어지지 않을때까지 나눈 수가 두 소수의 곱인 경우 (중복 가능)
bool checkCondition2(int n, int divisor){
    while(n % divisor == 0){
        n /= divisor;
    }
    // n 소인수분해
    int cnt = 0;
    // 비트 연산으로 최적화
    while((n & 1) == 0){
        n >>= 1;
        cnt++;
        if(cnt > 2){
            return false;
        }
    }
    
    for(int i = 3; i <= n; i += 2){ // n까지 돌아야
        while(n % i == 0){
            n /= i;
            cnt++;
            if(cnt > 2){
                return false;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

int convertNum(vector<int>& arr){
    int result = 0;
    for(int num : arr){
        result = result * 10 + num;
    }
    return result;
}

int power(int n, int k){
    int result = 1;
    for(int i = 0; i < k; i++){
        result *= n;
    }
    return result;
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int length, divisor;
    cin >> length >> divisor;

    initPrimeList();

    // solving
    int count = 0, num = 0;
    vector<bool> selected(SIZE, false);
    fill(selected.end() - length, selected.end(), true);
    
    do{
        vector<int> temp;
        for(int i = 0; i < SIZE; i++){
            if(selected[i]) temp.push_back(i);
        }
        do{
            if(temp[0] == 0) continue;

            int target = convertNum(temp);
            if(checkCondition1(target) && checkCondition2(target, divisor)){
                count++;
            }

        }while(next_permutation(temp.begin(), temp.end()));
    }while(next_permutation(selected.begin(), selected.end()));

    cout << count;
    
	return 0;
}

void initPrimeList(){
    fill(isPrime, isPrime + MAX, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i <= MAX; i++){
        if(isPrime[i]){
            for(int j = i * 2; j <= MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
}

/* comment
참고
- 2보다 큰 모든 짝수는 두개의 소수의 합으로 나타낼 수 있다 - 골드바흐 추측
ㄴ 근데 여긴 '서로 다른' 두 소수 합임


특징
- 소인수분해 -> 이때 소수 판별할 필요 없음
- k에 따른 경우의 수 - 
    k == 1) 10P1 - 10P0 = 9 (0으로 시작 X; 10 - 1)
    k == 2) 10P2 - 10P1 = 80 (90 - 10)
    k == 3 ) 10P3 - 10P2 = 630 (720 - 90)
    k == 4 ) 10P4 - 10P3 = 4320 (5040 - 720)
    k == 5 ) 10P5 - 10P4 = 25400 ( - 5040)

풀이
1) 조합으로 숫자 생성
2) 생성한 숫자가 조건 1, 2 모두 만족하는지 판별
ㄴ시간초과

- 에라토스테네스의 체 사용하니까 풀림
*/