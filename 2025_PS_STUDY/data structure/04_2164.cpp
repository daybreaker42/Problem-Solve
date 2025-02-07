#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    queue<int> q;
    bool dump = true;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(q.size() > 1){
        if(dump){
            // cout << q.front() << "����\n";
            q.pop();
        }else{
            // cout << q.front() << "�ڷ� ����\n";
            q.push(q.front());
            q.pop();
        }
        dump = !dump;
    }

    cout << q.front();

	return 0;
}

/* comment - 250207
- ������ ���缭 �ϳ��� ������ �ϳ��� �ڷ� ������ ��Ģ
- ������ �ϳ��� ���������� �ݺ�
*/