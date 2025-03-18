#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define SIZE 100001
using namespace std;

priority_queue<pii> desc;
priority_queue<pii, vector<pii>, greater<pii>> asc;
set<pii> desc_delete_reserved, asc_delete_reserved;

// map<int, int> desc_list, asc_list;       // {문제번호, 난이도 저장}, 현재 추천 리스트에 들어있는 문제 번호의 난이도를 저장함

unsigned short problem_num_level[SIZE];     // {문제번호, 난이도 저장}, 현재 추천 리스트에 들어있는 문제 번호의 난이도를 저장함 / 없으면 -1, 있으면 난이도 (1~100) 저장


// 요소 하나 추가 / 삭제 예약에 있다면 뺌
void add_one(pii problem){
    if(desc_delete_reserved.find(problem) != desc_delete_reserved.end()){
        // 삭제 리스트에 있다면 뺌
        desc_delete_reserved.erase(problem);
    }else{
        // 없으면 그대로 추가
        desc.push(problem);
    }
    if(asc_delete_reserved.find(problem) != asc_delete_reserved.end()){
        asc_delete_reserved.erase(problem);
    }else{
        asc.push(problem);
    }
}

// 둘 다에서 특정 요소 하나 삭제 / 없다면 reserve
void delete_one(pii problem){
    if(!desc.empty()){
        if(desc.top() == problem){
            desc.pop();
        }else{
            desc_delete_reserved.insert(problem);
        }
    }

    if(!asc.empty()){
        if(asc.top() == problem){
            asc.pop();
        }else{
            asc_delete_reserved.insert(problem);
        }
    }
}

// desc와 asc 모두 top이 delete 대상일경우 삭제
void check_top_delete_both(){
    while(!desc.empty() && desc_delete_reserved.find(desc.top()) != desc_delete_reserved.end()){
        desc_delete_reserved.erase(desc.top());
        desc.pop();
    }
    while(!asc.empty() && asc_delete_reserved.find(asc.top()) != asc_delete_reserved.end()){
        asc_delete_reserved.erase(asc.top());
        asc.pop();
    }
}

int main(){
    fastio;
    memset(problem_num_level, -1, sizeof(problem_num_level));
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p, l;
        cin >> p >> l;
        desc.push({l, p});
        asc.push({l, p});
        problem_num_level[p] = l;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int p, l, x;           // p - 문제번호, l - 난이도, x - 문제 추천 방법
        string command;
        cin >> command;
        if(!command.compare("add")){
            // 문제 추가
            cin >> p >> l;
            add_one({l, p});        // 없는 것만 주어짐; 있던게 다시 들어올 수 있음음
            problem_num_level[p] = l;
        }else if(!command.compare("solved")){
            // 문제 삭제 (해결됨)
            cin >> p;
            l = problem_num_level[p];
            delete_one({l, p});
            problem_num_level[p] = -1;
        }else{
            // 추천 문제 출력
            cin >> x;
            check_top_delete_both();
            if(x == 1){
                // 가장 어려운거
                cout << desc.top().second << "\n";
            }else{
                cout << asc.top().second << "\n";
            }
        }
    }
}
/* comment - 250311
- double priority queue 쓰는 문제
- 난이도 겹칠 수도 있어서 map 못씀 / (multimap은 정렬 불가)

- 이중 우선순위 큐 문제.
    - 양쪽으로 우선순위 큐 만들고, 삭제가 안되면 삭제 예약을 해놨다가 나중에 삭제.

// 19998 78
1402 59
2042 55
2667 37
1001 2
// 1000 1
*/