#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

// const bool debug = false;

// origin을 base진법으로 계산시 10진법 정수를 구하는 함수
// base진법으로 변환 불가시 -1 return
ll convertNum(string origin, int base){
    // 이전에 base 진법으로 표현 가능한지 판별
    for(char c : origin){
        // 각 자리가 0~9일때 검사
        if(c <= '9' && c >= base + '0'){
            return -1;
        }
        // 각 자리가 a~z일때 검사
        if(c >= 'a' && c >= base - 10 + 'a'){
            return -1;
        }
    }

    // 변환가능시 base 진법으로 변환, 여전히 overflow날 수 있음
    ll result = 0;
    for(char c : origin){
        int currPosition = 0;
        if('0' <= c && c <= '9'){
            currPosition = c - '0';
        }else{
            currPosition = c - 'a' + 10;
        }
        result = currPosition + result * base;
    }
    // X는 long long 범위 이내이므로 overflow시 -1 return
    if(result < 0) return -1;
    return result;
}

int main() {
	fastio;

	freopen("input.txt", "r", stdin);

    string val1, val2;
    cin >> val1 >> val2;

    // solving
    int a, b;
    ll x;
    bool solvable = false;
    for(int i = 2; i <= 36; i++){
        for(int j = 2; j <= 36; j++){
            // 문제조건 : A != B
            if(i == j) continue;
            ll convResult1 = convertNum(val1, i);
            if(convResult1 < 0) break;
            ll convResult2 = convertNum(val2, j);
            if(convResult2 < 0) continue;

            // cout << "conv - " << convResult1 << " / " << convResult2 << "\n";
            if(convResult1 == convResult2){
                // 답이 여러개인 경우
                if(solvable){
                    cout << "Multiple";
                    return 0;
                }
                // 풀 수 있는 경우
                solvable = true;
                x = convResult1;
                a = i;
                b = j;
            }
        }   
    }

    if(solvable){
        cout << x << " " << a << " " << b;
    }else{
        cout << "Impossible";
    }

	return 0;
}

/*
고려할 점
- 변환시 long long을 넘어가는 경우 -> 이후 경우는 impossible 처리해야 함
- 답이 2개임이 확인된 시점에 Multiple 출력 후 프로그램 종료하기
- 해당 string이 base 진법으로 변환 가능한지부터 check

풀이
- val1을 2~36진법으로 변환한 결과를 get
- val2를 2~36진법으로 변환한 결과를 get
- 두 결과중 일치하는 경우가 없음 -> Impossible
- 1개 -> 출력
- 2개 이상 -> Multiple

comment 
- isalpha(); isdigit(); 등의 함수를 활용했어도 좋았을 듯.
- 기존 python 코드 -> 
    1) 각 숫자별 필요 최소 base 설정
    2) 각 숫자마다 가능한 base별로 가능한 X list 생성
    3) a list에 있는 숫자가 b list에 있는 개수 세서 ans 판별
- 이번에 개선한 점
    1) convert 함수 따로 만들어서 진법별 변환 간편화 + convert함수에서 누적곱 이용해 계산 최적화
    2) 실시간으로 비교하면서 답을 찾아감 -> 2개째 찾으면 조기 종료로 최적화
*/

// ai solution
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

// 문자를 숫자로 변환하는 함수
int charToNum(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'a' + 10;
}

// 진법 변환 함수
ll convert(string str, int base) {
    ll result = 0;
    
    // 각 자리수가 진법보다 작은지 확인
    for (char c : str) {
        if (charToNum(c) >= base) return -1;
    }
    
    // 진법 변환 수행
    for (char c : str) {
        // 오버플로우 체크
        if (result > (LLONG_MAX - charToNum(c)) / base) 
            return -1;
        result = result * base + charToNum(c);
    }
    
    return result;
}

int main() {
    fastio;
    string num1, num2;
    cin >> num1 >> num2;
    
    ll X = -1;
    int A = -1, B = -1;
    bool found = false;
    
    // 가능한 모든 진법 조합 확인
    for (int i = 2; i <= 36; i++) {
        for (int j = 2; j <= 36; j++) {
            if (i == j) continue;  // A ≠ B
            
            ll val1 = convert(num1, i);
            if (val1 == -1) continue;
            
            ll val2 = convert(num2, j);
            if (val2 == -1) continue;
            
            // 두 변환 결과가 같은 경우
            if (val1 == val2) {
                if (found) {  // 이미 답을 찾은 경우
                    cout << "Multiple";
                    return 0;
                }
                found = true;
                X = val1;
                A = i;
                B = j;
            }
        }
    }
    
    if (found) {
        cout << X << " " << A << " " << B;
    } else {
        cout << "Impossible";
    }
    
    return 0;
}
*/

/*
코드 설명
함수 구현

charToNum: 문자를 해당하는 숫자로 변환
convert: 문자열을 특정 진법의 수로 변환
주요 처리

오버플로우 체크: LLONG_MAX 사용
진법 범위 검사: 각 자리수가 진법보다 작은지 확인
중복 답안 처리: found 변수로 관리
추천 추가 질문
큰 수의 진법 변환을 위한 더 효율적인 알고리즘은?
오버플로우 처리의 다른 방법들은?
병렬 처리로 성능 개선이 가능할까?
질문 평가
문제의 핵심을 잘 파악했지만, 구체적인 입력 예시와 테스트 케이스를 포함했다면 더 좋았을 것 같습니다.
*/