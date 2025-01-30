#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10000000

using namespace std;

bool primeList[SIZE + 1] = {0}; // idx => 실제 숫자 사용 / n이 소수인 경우 - primeList[n] == true, 그 외 false

// const bool debug = false;

void initPrimeList();
int findNextPrime(int prev);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    // solving
    initPrimeList();
    
    int divisor = findNextPrime(1);
    while(n > 1){
        while(n % divisor != 0){
            divisor = findNextPrime(divisor);
        }

        n /= divisor;
        cout << divisor << "\n";
    }


	return 0;
}

void initPrimeList(){
    fill(primeList, primeList + SIZE + 1, true);
    primeList[1] = false;
    for(int i = 2; i <= SIZE; i++){
        if(primeList[i]){
            for(int j = 2 * i; j < SIZE + 1; j += i){
                primeList[j] = false;
            }
        }
    }
}

int findNextPrime(int prev){
    int idx = prev + 1;
    if(idx > SIZE + 1) return -1;
    while(!primeList[idx]) idx++;
    return idx;
}

/** comment
 * 1. 에라토스테네스의 체를 사용, 1~SIZE까지의 소수 리스트를 구함
 * 2. 에라토스테네스의 체를 순회하면서 각 소수로 나눠지는지 판별
 * 3. 소인수분해서 작은 소수부터 나눠짐 -> 해당 소수가 나눠지지 않는다면 다음으로 가장 작은 소수를 찾아 시도, 반복.
 * 4. n == 1일때 반복 종료
 * 
 * ai 솔루션 -> 굳이 소수를 판별할 필요 X
 *  - 왜?? 대체 왜???
 */

