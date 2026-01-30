#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, bool>
using namespace std;

// const bool debug = false;
// board 회전
void transpose(int n, int dir, vector<vector<pii>> & board){
  if(dir == 1){
    // up - 아무것도 x
    return;
  }else if(dir == 2){
    // down - 점대칭
    vector<vector<pii>> newBoard(n, vector<pii>(n, {0, 0}));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        int new_i = n - i - 1, new_j = n - j - 1;
        newBoard[new_i][new_j] = board[i][j];
      }
    }
    board = newBoard;
  }else if(dir == 3){
    // left - 오른쪽 한번
    vector<vector<pii>> newBoard(n, vector<pii>(n, {0, 0}));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        int new_i = j, new_j = n - i - 1;
        newBoard[new_i][new_j] = board[i][j];
      }
    }
    board = newBoard;
  }else if(dir == 4){
    // right - 왼쪽으로 한번
    vector<vector<pii>> newBoard(n, vector<pii>(n, {0, 0}));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        int new_i = n - j - 1, new_j = i;
        newBoard[new_i][new_j] = board[i][j];
      }
    }
    board = newBoard;
  }
}


void moveBoard(int n, int dir, vector<vector<pii>> & board){

  transpose(n, dir, board);
  for(int j = 0; j < n; j++){
    // 각 열을 반복
    int front_i = -1; // 해당 열에서 숫자가 있는 가장 마지막 행, 위에 다 비어있으면 -1
    if(board[0][j].first >= 2){
      front_i = 0;
    }
    for(int i = 1; i < n; i++){ // 어차피 맨 위에 있는 애는 못움직이니까 건너뛰고 다음 애부터 시작
      if(board[i][j].first == 0) continue;  // 비어있으면 continue
      if(front_i < 0){
        // 맨 위에 아무것도 없는 경우 - 이동
        board[0][j] = board[i][j];
        board[i][j] = {0, 0};
        front_i = 0;
      }else{
        // 숫자 있는 경우
        // 1. merge확인
        if(board[front_i][j].first == board[i][j].first && !board[front_i][j].second && !board[i][j].second){
          // merge 가능
          board[front_i][j].first *= 2;
          board[front_i][j].second = true;
          board[i][j] = {0, 0};
        }else{
          // merge 불가 - 이동
          front_i++;
          if(front_i == i) continue;  // 만약 front_i == i라면 다음 동작 취소
          board[front_i][j] = board[i][j];
          board[i][j] = {0, 0};
        }
      }
    }
  }
  if(dir == 1){
    // up - 아무것도 x
  }else if(dir == 2){
    // down
    transpose(n, 2, board);
  }else if(dir == 3){
    // left
    transpose(n, 4, board);
  }else if(dir == 4){
    // right
    transpose(n, 3, board);
  }
}

// board merge flag 초기환
void initBoardMerge(int n, vector<vector<pii>> & board){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      board[i][j].second = false;
    } 
  }
}

// board에서 제일 큰 수 return
int getMax(int n, vector<vector<pii>> & board){
  int maxNum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      maxNum = max(maxNum, board[i][j].first);
    } 
  }
  return maxNum;
}

// 횟수에 맞게 재귀돌려서 제일 큰 수 return
int recursive(int n, int level, vector<vector<pii>> board){
  int maxNum = 0;
  if(level == 0) return getMax(n, board);
  for(int dir = 1; dir <= 4; dir++){
    vector<vector<pii>> newBoard = board;
    moveBoard(n, dir, newBoard);
    initBoardMerge(n, newBoard);
    maxNum = max(maxNum, recursive(n, level - 1, newBoard));
  }
  return maxNum;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<vector<pii>> board(n, vector<pii>(n, {0, 0})); // { 숫자, 합쳐짐 여부 }, 숫자 0이면 그 자리에 숫자 없음
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j].first;
    } 
  }

  // solve
  int maxNum = recursive(n, 5, board);
  cout << maxNum;

	// system("pause");
	return 0;
}

/* comment - 260131
- 단순 구현 문제
- 실수 2번
  1. transpose에서 index 실수 - n - j - 1으로 해야했었는데 -1 까먹음
  2. initBoardMerge 까먹음 - 이거 안하면 한 번 merge하고나서 다음에 merge 안함


*/