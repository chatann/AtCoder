n, m = map(int, input().split())
c = list(input().split())
d = list(input().split())
p = list(map(int, input().split()))

sum = 0
for i in range(n):
    other = 1
    for j in range(m):
        if c[i] == d[j]:
            sum += p[j+1]
            other = 0
    if other == 1:
        sum += p[0]

print(sum)