# algo-mehtod : 個数制限付き部分和問題

n, m = map(int, input().split())
a, b = [], []
for i in range(n):
    a_, b_ = map(int, input().split())
    a.append(a_)
    b.append(b_)

INF = 10**29

dp = [[INF for _ in range(m + 1)] for _ in range(n + 1)]
for i in range(n+1):
    dp[i][0] = 0

for i in range(n):
    for j in range(m + 1):
        if dp[i][j] < INF:
            dp[i+1][j] = 0
        if j - a[i] >= 0:
            dp[i+1][j] = min(dp[i+1][j], 1)
        if dp[i+1][j-a[i]] < b[i]:
            dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-a[i]] + 1)

if dp[n][m] < INF:
    print('Yes')
else:
    print('No')