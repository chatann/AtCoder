from datetime import datetime
from math import floor

a, b, c, d = map(int, input().split())
n = int(input())
data = []
for i in range(n):
    data.append(input())

ans = 0
for line in data:
    fare = b
    t, l = line.split()
    t = datetime.strptime(t, "%H:%M")
    l = int(l)
    if l > a:
        fare += d
        while l - a > c:
            fare += d
            l -= c
    if t.hour < 22:
        ans += fare
    else:
        ans += floor(fare * 1.2)

print(ans)