import sys
'''

'''
n, m = map(int, sys.stdin.readline().split())
lst = list(map(int, sys.stdin.readline().split()))
ans = -1

# 1. lst 정렬
lst.sort()

# # 2. 3중반복문 돌면서 진행, 단 m을 넘어가면 다음 숫자로
for i_idx, i in enumerate(lst):
  if i >= m:
    break
  for j_idx, j in enumerate(lst):
    if i_idx == j_idx:
      # 같으면 넘어감
      continue
    elif i + j >= m:
      break
    for k_idx, k in enumerate(lst):
      if i_idx == k_idx or j_idx == k_idx:
        # 같으면 넘어감
        continue
      total = i + j + k
      if total > m:
        # m을 넘어가면 - 중단
        break
      elif m - ans > m - total:
        # 차이가 더 적으면 - 갱신
        ans = total

print(ans)
