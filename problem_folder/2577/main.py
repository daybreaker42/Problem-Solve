a = int(input())
b = int(input())
c = int(input())

total = a * b * c

count_lst = [0 for i in range(10)]

for ch in str(total):
  count_lst[int(ch)] += 1

for i in count_lst:
  print(i)