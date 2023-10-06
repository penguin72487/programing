k,q,r = map(int,input().split())
now = list(input())
last = now.copy()
data = []
for i in range(q):
    quest =list(map(int,input().split()))
    for j in range(k):
        now[quest[j]-1] = last[j]
    last = now.copy()
    # print(now)
    data.append(now.copy())
    # print("")

for i in range(r):
    for j in range(q):
        print(data[j][i],end="")

    
