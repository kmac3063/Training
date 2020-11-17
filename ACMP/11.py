k, n = input().split()
k = int(k)
n = int(n)
dp = []
for i in range(n + 1):
    dp.append(0)
dp[0] = 1
for i in range(n + 1):
    for j in range(1, k + 1):
        if (i + j <= n):
            dp[i + j] += dp[i]
print(dp[n])

