n = int(input())
a = list(map(int, input().split()))
ans = 0
if a[0] == 0:
    a[0] = a[1]
    ans += a[0]
if a[n - 1] == 0:
    a[n - 1] = a[n - 2]
    ans += a[n - 1]
for i in range(n):
    if a[i] == 0:
        a[i] = min(a[i - 1], a[i + 1])
        ans += a[i]
print(ans)
