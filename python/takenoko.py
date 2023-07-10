n = int(input())
a = list(map(int, input().split()))

ans = -1
b = set()
for i in range(n):
    if a[i] in b:
        ans = i + 1
        break
    b.add(a[i])

print(ans)