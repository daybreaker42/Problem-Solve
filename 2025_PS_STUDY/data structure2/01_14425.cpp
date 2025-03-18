#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    set<string> s;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    // solving
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if(s.find(str) != s.end()){
            cnt++;
        }
    }
    
    cout << cnt;

	return 0;
}

/* comment - 250302
set 이용해서 집합 내 포함되는지 판별하면 되는 문제



*/