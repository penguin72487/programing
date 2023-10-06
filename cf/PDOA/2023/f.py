# n = int(input())
# cas = list(map(int, input().split()))
# cas.sort()
# flag = True
# k = cas[1] - cas[0]
# if len(cas) > 3:
#     if (cas[1]-cas[0]) != (cas[2]-cas[1])/2:
#         if (cas[0])/2 == (cas[3]-cas[2])/3:
#             flag = False
#             print(1)
#         if (cas[2]-cas[1])/3 == (cas[3]-cas[2])/4:
#             k = (cas[2]-cas[1])/3
#         else:
#             k = cas[1] - cas[0]
# if flag:
#     now = cas[0]
#     for i in range(len(cas)):
#         if cas[i] != now+k*i:
#             print(i+1)
#             break
#         now += k*i


n = int(input())
cas = list(map(int, input().split()))
cas.sort()

k = cas[0]
if len(cas) > 3:
    if (cas[1]-cas[0])/2 != (cas[2]-cas[1])/3:
        if (cas[2]-cas[1])/3 == (cas[3]-cas[2])/4:
            k = (cas[2]-cas[1])/3 
        else:
            k = cas[1] - cas[0]

now = cas[0]
for i in range(len(cas)):
    if cas[i] != now+k*i:
        print(i+1)
        break
    now += k*i