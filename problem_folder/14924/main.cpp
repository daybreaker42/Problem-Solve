#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
  int s, t, d;
  cin >> s >> t >> d;

  int flyDist = 0, movingTime = 0;
  movingTime = d / s / 2;
  flyDist = t * movingTime;
  cout << flyDist;

	// system("pause");
	return 0;
}

/* comment 



*/