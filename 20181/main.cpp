#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
using namespace std;

// const bool debug = false;

int food[SIZE];

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> food[i];
    }
    
    // solving
    int satisfy = 0, ans = 0;
    int ed = 0;
    for (int st = 0; st < n; st++)
    {
        satisfy += food[ed];
        while(satisfy)
    }
    

	return 0;
}

/* comment 
6 9 8 6 15 13 10 8 5


*/