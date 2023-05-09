def lengthOfLIS(nums) -> int:
    dp = [1] * len(nums)
    for i, val in enumerate(nums):
        dp[i] = max([dp[j] + 1 for j in range(0, i) if nums[j] < nums[i]], default=1)
    return max(dp, default=0)

love = []
suger = []
ans = []
n = int(input())
for i in range(n):
    a = list(map(int, input().split()))
    love.append(a[0])
    suger.append(a[1])
sorted_s = sorted(range(len(suger)), key = lambda k : suger[k])
sorted_s.reverse()
k = lengthOfLIS(sorted_s)
if k >= 3:
    print(True)
else:
    print(False)

