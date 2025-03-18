#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

bool findStr(string str, vector<string>& v){
    for(int i = 0; i < v.size(); i++){
        if(!v[i].compare(str)){
            return true;
        }
    }
    return false;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<string> v;
    v.reserve(10000);
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    // solving
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if(findStr(str, v)){
            cnt++;
        }
    }
    
    cout << cnt;

	return 0;
}

/* comment - 250302
- brute force 이용해 풀어본 문제 -> 시간초과.. 아마 비교 자체는 O(N^2)인데, string비교가 시간이 걸려 그런듯



*/