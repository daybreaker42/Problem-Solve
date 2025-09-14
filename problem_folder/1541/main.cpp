#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

void handle_number(int number, bool isplus, bool *reversed, int *result_val){
  // 기호 등장 시
  if(*reversed){
    *result_val -= number;
  }else{
    if(isplus){
      // 그냥 더함
      *result_val += number;
    }else{
      // 처음 - 나옴
      *result_val -= number;
      *reversed = true;
    }
  }
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
  string str;
  getline(cin, str);

  const int length = str.length();
  bool reversed = false;  // - 구간 여부 저장
  int result_val = 0;
  // int section_sum = 0;
  string curr_number_str = "";
  int curr_number = 0;
  bool isplus = true;
  for(int i = 0; i < length; i++){
    if(isdigit(str[i])){
      // 숫자면
      curr_number_str += str[i];
      if(i == length - 1){
        if(curr_number_str.length() > 0){
          curr_number = stoi(curr_number_str);
          curr_number_str = "";
        }

        handle_number(curr_number, isplus, &reversed, &result_val); 
      }
    }else{
      // 현재 숫자 세팅
      if(curr_number_str.length() > 0){
        curr_number = stoi(curr_number_str);
        curr_number_str = "";
      }

      handle_number(curr_number, isplus, &reversed, &result_val);

      isplus = str[i] == '+';
    }
  }

  cout << result_val;

	// system("pause");
	return 0;
}

/* comment - 250915 solved
1. -가 나온 이후, 다음 -가 나오기 전까지의 구간을 괄호처리한다.
2. -가 한번이라도 나왔다면, 이후 값들은 전부 음수 처리한다. -> solved!

*/