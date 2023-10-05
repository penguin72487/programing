import sys

n, m = map(int, sys.stdin.readline().split())

cost = [0 for item in range(n + 1)]

for i in range(m):
    a = list(map(int, input().split()))
    cost[a[0] - 1] += a[2]
    cost[a[1]] -= a[2]

a = 0

for i in range(n):
    a += cost[i]
    cost[i] = a
cost.sort()
cost.reverse()
ans = 0
ll = list(map(int, input().split()))
ll.sort()
for i in range(n):
    ans += ll[i] * cost[i]
print(ans)
