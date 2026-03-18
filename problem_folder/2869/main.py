import sys, math
a, b, v = map(int, sys.stdin.readline().split())

ans = math.ceil((v - a) / (a - b))

print(ans + 1)
