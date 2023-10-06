n = int(input())
i_Max = -2
time = 0
error = 0
for i in range(n):
    t = list(map(int,input().split()))
    if t[1]==-1:
        error+=1
        continue
    
    if t[1]>i_Max:
        i_Max = t[1]
        time = t[0]
    
print(max(i_Max-n-error*2,0),time)
    
    
    