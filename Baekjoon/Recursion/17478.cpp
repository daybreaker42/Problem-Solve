// Baekjoon No. 17478 - ����Լ��� ������?
// 220812 solved
#include <iostream>
using namespace std;

void recursion(int n, int depth);
void printSlash(int index);
int main(){
    ios::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    recursion(n, 0);
    return 0;
}
void recursion(int n, int depth){
    int i = 0;
    printSlash(depth);
    printf("\"����Լ��� ������?\"\n");
    
    if(n == depth){
        printSlash(depth);
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
    }else{
        printSlash(depth);
        printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
        printSlash(depth);
        printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
        printSlash(depth);
        printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
        recursion(n, depth+1);
    }
    printSlash(depth);
    printf("��� �亯�Ͽ���.\n");
    return;
}
void printSlash(int index){
    for(int i = 0; i < index; i++)
        printf("____");
    return;
}