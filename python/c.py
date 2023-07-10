n = int(input())
a = []
b = []

prob = []
for i in range(n):
    ai, bi = map(float, input().split())
    prob.append([i, ai / (ai + bi)])

prob.sort(key=lambda x: (-x[1],x[0]))
ans = []
for i in range(n):
    ans.append(prob[i][0] + 1)

print(*ans, sep=" ")