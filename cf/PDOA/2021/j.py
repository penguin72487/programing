n = int(input())
in_ = list(map(int,input().split()))
cas = []
for i in range(len(in_)-1):
    if in_[i] == in_[i+1]:
        cas.append(-1)
    elif in_[i] > in_[i+1]:
        cas.append(0)
    else:
        cas.append(1)

long = 0
start = 0
while start < n:
    start = now
    cas = 0
    now = 0
    while now < n-2:
        if cas[now] == -1:
            now += 1
            continue
        if cas[now] != cas[now+1]:
            cas += 1
            now += 1
        else:
            now += 1
    
    start += 1
    long = max(long,now)