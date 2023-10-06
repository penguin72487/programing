def max_Subarray(arr)-> int:
    ans = arr[0]
    su = 0
    for a in arr:
        su += a
        ans = max(su, ans)
        if su < 0:
            su = 0
    return ans

def int_to_letter(x) -> str:
    ans = ""
    if x== 0:
        return "A"
    while x > 0:
        ans += chr(x%10+65)
        x //= 10
    return ans[::-1]

n , m = map(int, input().split())
ans = []
for i in range(n):
    ans.append(input())