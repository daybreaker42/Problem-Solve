#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int fibo[50];

int getFibo(int n){
  if(n < 2){
    return fibo[n];
  }
  if(fibo[n] > 0) return fibo[n];
  return fibo[n] = getFibo(n - 1) + getFibo(n - 2);
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);

  int n; cin >> n;
  fibo[1] = 1;
  cout << getFibo(n);

	// system("pause");
	return 0;
}

/* comment - 250915 solved
1. 기존 fibo를 저장하면서, 값이 있으먄 return, 없으면 구해서 저장 후 return
- 0번째 fibo가 0임에 조심

*/