cas = ["Eason","Emil"]
n = int(input())

for i in range(n):
    in_ = list(map(int,input().split()))
    if in_[0] == in_[1]:
        if in_[2] == 0:
            in_[2] = 1
        else:
            in_[2] = 0
            
        print(f"{cas[in_[2]]}")
    else:
        if in_[0] > in_[1]:
            print(f"{cas[0]}")
        else:
            print(f"{cas[1]}")