#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;
struct point{
    int st;
    int ed;
};


int main() {
	fastio;

	// freopen("zagrade/zagrade.in.6", "r", stdin);
    string str;
    cin >> str;

    // solving
    set<string> check_ans;
    vector<string> ans;
    ans.reserve(1024);      // 최대 정답 - 2^10개
    int braketNum = 0;

    // 1. 모든 괄호쌍 정보 파악 - O(n), n <= 200
    stack<int> s;
    map<int, int> braket_idx;       // {str_idx, braket_idx} / 반대로 str에서의 idx를 통해 해당 braket이 몇 번째 세트인지 알 수 있음, 하나의 braket_idx당 str_idx는 시작/끝 2개 저장됨
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            s.push(i);
        }else if(str[i] == ')'){
            // 쌍이 정해짐 -> {str_idx, braket_idx}를 braket_idx에 저장
            braket_idx[s.top()] = braketNum;
            braket_idx[i] = braketNum;
            braketNum++;
            s.pop();
        }
    }

    // 2. 모든 가능한 조합 구하기 - 200 * 2^10 ~= 20만
    bitset<10> b1;  // 00 0000 0000 ~ 11 1111 1110 / 0~1023
    for(int case_idx = 0; case_idx < pow(2, braketNum) - 1; case_idx++){    // 모두 1인 경우는 제외
        b1 = bitset<10>(case_idx);

        string temp;
        for(int str_idx = 0; str_idx < str.length(); str_idx++){
            if(str[str_idx] == '(' || str[str_idx] == ')'){
                // 괄호 나왔을때 -> 해당 괄호쌍 추가시에만 temp에 추가
                int b_idx = braket_idx[str_idx];    // 원본 인덱스를 이용해 해당 braket의 idx를 구함
                if(b1[b_idx]){
                    // 만약 해당 braket이 사용된다면 temp에 추가
                    temp += str[str_idx];
                }
            }else{
                // 괄호 말고 다른거 -> 바로 추가
                temp += str[str_idx];
            }
        }
        // set로 겹치지 않는지 체크
        if(check_ans.find(temp) == check_ans.end()){
            ans.push_back(temp);
            check_ans.insert(temp);
        }
    }

    // 3. 정렬 - O(nlogn), n <= 2^10
    sort(ans.begin(), ans.end());

    // 4. 출력 - O(n), n <= 2^10
    for(const string& curr : ans){
        cout << curr << "\n";
    }

	return 0;
}

/* comment 
아이디어)
- 일단 어떤 괄호가 어떤 괄호의 쌍인지 한번 돌면서 파악 가능
- 모든 괄호쌍의 정보를 파악 후 -> 각 괄호쌍이 있는 경우와 없는 경우의 모든 조합 (모두 있는 경우 제외)을 구한다
- ans에 모든 조합을 저장 후, 정렬
- 정렬 후 출력

주의
+ '서로 다른' 괄호를 출력 -> 겹치면 안됨 -> set으로 체크
*/