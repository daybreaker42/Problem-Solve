def palidrome(k):       # ��Ī�� ã�� �Լ�, O(logn)
    k = str(k)
    length = len(k)
    for i in range(length//2):
        if k[i] != k[length - i - 1]:
            return 0
    return 1

n = 1
lychrel = 0         # ����ũ�� ���� ����
while n <= 10000:   # 10000���� �ݺ�
    cnt = 0         # ��Ī�� �Ǵ��� üũ
    standard_n = n  # ���ϴ� �� n �� ù��° n, ��Ī�Ǵ� n�� reversed_n
    for i in range(50):
        reversed_n = int(''.join(reversed(str(standard_n))))
        sum_n = standard_n + reversed_n
        if palidrome(sum_n):
            cnt += 1    # ��Ī���� �ȴٸ� break
            #print(sum_n)
            break
        else:
            standard_n = sum_n
    if cnt == 0:    # 50������ ��Ī���� �ϳ��� ���ٸ�
        lychrel += 1
    n += 1
print(lychrel)
    