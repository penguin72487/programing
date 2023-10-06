from itertools import accumulate

n, m = map(int, input().split())
tasks = [0 for _ in range(n + 1)]
for i in range(m):
    l, r, w = map(int, input().split())
    tasks[l - 1] += w
    tasks[r] -= w
tasks = list(accumulate(tasks))
tasks.sort(reverse=True)
t = list(map(int, input().split()))
t.sort()
minTime = sum(list(map(lambda task, singleTime: task * singleTime, tasks, t)))
print(minTime)
