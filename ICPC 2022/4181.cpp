// Baekjoon No. 4181 Convex hull - 220921~
// Time Complexity
// #Convex hull, CCW

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
int ccw(int, int, int, int, int, int);
bool compY(vector<int> i, vector<int> j);
bool compX(vector<int> i, vector<int> j);
double retrieveAngleCos(vector<int> i, vector<int> j);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    char c;
    int i, j;
    cin >> n;
    vector<vector<int>> coord;
    for (i = 0; i < n; i++) {
        cin >> x >> y >> c;
        if (c == 'Y')   // Y�� ��쿡�� push
            coord.push_back(vector<int> { y, x });
    }
    // solving
    for (i = 0; i < coord.size(); i++)
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    // 1) y sort
    stable_sort(coord.begin(), coord.end(), compY);
    // 2) x sort
    stable_sort(coord.begin(), coord.end(), compX);
    // test
    printf("sorted\n");
    for (i = 0; i < coord.size(); i++)
        cout << coord[i][0] << " " << coord[i][1] << "\n";
    
    // 3) stack�� 2�� �ְ�, ��� �ϳ� pop�ϸ鼭 ��, coord �ȿ� �ִ°� �� ���ؼ� stack�� �־����� ���
    stack<vector<int>> stack1;
    stack1.push(coord[0]);
    stack1.push(coord[1]);
    
    stack1.top();

    i = 2;
    while (i < coord.size()) {
        vector<int> first, second;
        first = stack1.top();
        stack1.pop();
        second = stack1.top();
        while (ccw(second[0], second[1], first[0], first[1], coord[i][0], coord[i][1]) < 0) {
            first = second;
            stack1.pop();
            second = stack1.top();
        }
        stack1.push(first);
        stack1.push(coord[i]);
        
        i++;
    }

    // 4) stack ���� �ϳ��� ���鼭 �ٸ� stack�� ����, �� ��° stack�� pop �ݺ��ϸ鼭 ���
    stack<vector<int>> reversed_stack;
    while (stack1.size()) {
        reversed_stack.push(stack1.top());
        stack1.pop();
    }
    while (reversed_stack.size()) {
        printf("%d %d\n", reversed_stack.top()[1], reversed_stack.top()[0]);
        stack1.pop();
    }

    return 0;
}
int ccw(int y1, int x1, int y2, int x2, int y3, int x3) {
    return x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
}
bool compY(vector<int> i, vector<int> j) {
    return i[0] < j[0];
}
bool compX(vector<int> i, vector<int> j) {
    return i[1] < j[1];
}
// v-a�� ������ w-a�� ���� �� ū�� �Ǻ��ϴ� �Լ�
bool compAngle(vector<int> a, vector<int> v, vector<int> w) {
    return retrieveAngleCos(a, v) < retrieveAngleCos(a, w);
}

// y = -cosx - 1���� �����ϴ� �Լ�. x���� ���� ��츦 �ּڰ����� ����� ���� �̷� ��� ���.
// ���� �������� ���� ���� ����. x���� ���� ���� ���� �������� �ϹǷ� 0 < �� <= 180��
double retrieveAngleCos(vector<int> i, vector<int> j) {
    if (i[1] == j[1])   // x������ ���, y���� ���� ���� �� �����̹Ƿ� 180���� ���
        return 0;
    // else if (i[0] == j[0])  // y����
    //    return -1;
    else
        return -(i[0] - j[0]) / sqrt((i[0] - j[0]) * (i[0] - j[0]) + (i[1] - j[1]) * (i[1] - j[1])) - 1;
}