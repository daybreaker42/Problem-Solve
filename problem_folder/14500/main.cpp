#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;
int n, m;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }
  
  int maxSum = 0;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      // 1. ㅡ
      int sum = 0;
      if(j <= n - 4){
        sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
        maxSum = max(maxSum, sum);
      }
      // 2. ㅣ
      if(i <= m - 4){
        sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
        maxSum = max(maxSum, sum);
      }
      // 3. ㅁ
      if(i < m - 1 && j < m - 1){
        sum = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
        maxSum = max(maxSum, sum);
      }

      maxSum = max(maxSum, sum);
    }
  }

	// system("pause");
	return 0;
}

/* comment 



*/