n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
prod = 1
for i in range(n):
    prod *= a[i]
    while prod % k == 0:
        prod //= k
        ans += 1

print(ans)