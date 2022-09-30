#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n, t, maxNum, duo, tmp;
    int tc, i;
    scanf("%d", &t);
    for(tc = 0; tc < t; tc++){
        scanf(" %d", &n);
        vector<int> students(n, 0);
        vector<int> mentors(n, 0);
        vector<int> temp;
        priority_queue<int> m;
        for(i = 0; i < n; i++){
            scanf(" %d", &students[i]);
            m.push(students[i]);
        }
        
        // solving
        // ���� ū ���� 2�� ��ĥ ���� ���� ���䰡 �� �� ����.
        // �켱���� ť �̿��ؼ� ���� �ذ��Ϸ� �ߴµ� �ڱ� �ڽ��� ����� ������ ��츦 ���� �ذ����� ����.
        maxNum = m.top();
        m.pop();
        if(maxNum == m.top())
            duo = 1;
        else
            duo = 0;
        m.push(maxNum);
        
        for(i = 0; i < n; i++){
            // ���ǿ� ���� �ʴ� �͵��� ��� temp�� ���� 
            while(m.size() > 0 && m.top() > students[i] * 2){
                // printf("compare: %d %d\n", m.top(), students[i]);
                temp.push_back(m.top());
                m.pop();
            }
            // ť�� �����ִ� �͵� �߿��� ���� ū �� ����. ������ -1 ����.
            if(m.size() > 0){
                if(m.top() == maxNum && !duo){
                    tmp = m.top();
                    m.pop();
                    mentors[i] = m.top();
                    m.push(tmp);
                }
                else
                    mentors[i] = m.top();
            }else{
                mentors[i] = -1;
            }
            // �ٽ� �������
            while(temp.size() > 0){
                m.push(temp.back());
                temp.pop_back();
            }
                
        }

        // output
        printf("Case #%d:", tc+1);
        for(i = 0; i < n; i++)
            printf(" %d", mentors[i]);
        printf("\n");
    }
    

    return 0;
}