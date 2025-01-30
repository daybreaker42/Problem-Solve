#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fastio
    int a = 0, b = 0;
    cin >> a >> b;
    cout.precision(10);
    cout << (double)a / b;
}

/*
배운 점
- cpp에서 소수 이하 자릿수 지정 - `cout.precision(자릿수)`
- 10^-9 정확도가 꼭 소숫점 9자리까지 출력하라는건 아님
-> 소숫점 9번째자리에서 2 이상 차이가 나면 2*10^9 차이가 나는 것.
-> 소숫점 아래 10번째 자리까지 출력해야 함.
 */