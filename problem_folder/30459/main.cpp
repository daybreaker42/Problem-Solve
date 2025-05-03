#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> loc(n), heights(m);
    for (int i = 0; i < n; i++)
    {
        cin >> loc[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> heights[i];
    }
    
    // solving
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int left = -1, right = m;
            int mid = (left + right) / 2;
            while(left + 1 < right){
                if((loc[right] - loc[left]) * heights[mid] / 2 <= r){
                    
                }
            }
        }
    }


	return 0;
}

/* comment 



*/