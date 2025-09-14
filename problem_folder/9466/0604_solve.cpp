#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
using namespace std;

// const bool debug = false;
int cnt = 0;
int nextStudent[SIZE];
bool finished[SIZE];
bool visited[SIZE];

// curr에서 계속 다음 학생을 탐색하며, 만약 사이클이 형성됐다면(재방문이 일어났다면) 해당 사이클 내의 학생들을 finished를 true로 바꿈
int dfs(int curr) {
    visited[curr] = true;
    if (finished[curr]) return -1;   // 이미 스터디 있는 경우 -> 탐색 불필요

    int nextPerson = nextStudent[curr];
    if (finished[nextPerson]) return -1;
    if (visited[nextPerson]) {
        // 사이클 첫 발견 -> 돌아가면서 nextPerson까지 모두 스터디에 추가
        finished[curr] = true;
        cnt++;
        if (nextPerson == curr) return -1;
        return nextPerson;
    }

    int result = dfs(nextPerson);   // 방문 아직 안 했으면 방문
    if (result < 0) return -1;       // 실패 시 -> -1 return

    // 앞에서 성공한 경우
    finished[curr] = true;
    cnt++;
    // 다시 사이클 시작으로 돌아왔을 때 -> 이전 애들은 실패 처리
    if (result == curr) return -1;

    return result;
}

int main() {
    fastio;

    // freopen("../../input.txt", "r", stdin);
    int t; cin >> t;
    while (t-- > 0) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nextStudent[i];
            nextStudent[i] -= 1;
        }

        // solving
        cnt = n;
        memset(finished, false, SIZE * sizeof(finished[0]));
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {   // 이미 스터디 그룹 있으면 탐색 x
                memset(visited, false, SIZE * sizeof(visited[0]));
                dfs(i);     // 해당 노드부터 스터디 가능한지 탐색
            }
        }

        // output
        /*int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!finished[i]) cnt++;
        }*/
        cout << cnt << "\n";
    }

    return 0;
}

/* comment



*/