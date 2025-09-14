#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(str[0] == 'C'){
            ans++;
        }
    }
    cout << ans;

	return 0;
}

/* comment 



*/