# abc049 c - 白昼夢 / Daydream

s = input()

ans = "NO"
u = s
for i in range(len(s)):
    v = u[len(s)-i-1:len(s)]
    if v == "dream" or v == "erase" or v == "eraser" or v == "dreamer":
        u = u[:len(u)-len(v)]

if u == "":
    ans = "YES"

print(ans)
