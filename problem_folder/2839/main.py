import sys

n = int(sys.stdin.readline())

large_num = n // 5
small_num = 0

while large_num * 5 + small_num * 3 != n:
  curr = large_num * 5 + small_num * 3
  if curr > n:
    large_num -= 1
    small_num += 1
  else:
    small_num += 1
  if large_num == 0:
    break

if large_num * 5 + small_num * 3 == n:
  print(large_num + small_num)
else:
  print(-1)